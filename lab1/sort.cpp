#include <iostream>
#include <iomanip>
#include <random>
#include <chrono>
#include <string>
#include <cstring>
#include <windows.h>

using namespace std;

const int N = 100;
const int M = 100;
const int TOTAL = N * M;

long long comparisons = 0;
long long swaps = 0;

bool compare(int a, int b)
{
    comparisons++;
    return a < b;
}

void bubbleSort(int* a, int n)
{
    for (int i = 0; i < n - 1; i++)
        for (int j = 0; j < n - 1 - i; j++)
            if (compare(a[j + 1], a[j]))
            {
                swap(a[j], a[j + 1]);
                swaps++;
            }
}

void insertionSort(int* a, int n)
{
    for (int i = 1; i < n; i++)
    {
        int x = a[i];
        int j = i - 1;
        while (j >= 0 && compare(x, a[j]))
        {
            a[j + 1] = a[j];
            swaps++;
            j--;
        }
        a[j + 1] = x;
    }
}

void hoareSort(int* a, int l, int r)
{
    int i = l;
    int j = r;
    int x = a[(l + r) / 2];
    while (i <= j)
    {
        while (compare(a[i], x)) i++;
        while (compare(x, a[j])) j--;
        if (i <= j)
        {
            swap(a[i], a[j]);
            swaps++;
            i++;
            j--;
        }
    }
    if (l < j) hoareSort(a, l, j);
    if (i < r) hoareSort(a, i, r);
}

bool isSorted(int m[N][M])
{
    int* a = &m[0][0];
    for (int i = 1; i < TOTAL; i++)
        if (a[i] < a[i - 1]) return false;
    return true;
}

void printPart(int m[N][M], int rows, int cols)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
            cout << setw(5) << m[i][j];
        cout << "  ...\n";
    }
    cout << "  ...\n";
    for (int j = 0; j < cols; j++)
        cout << setw(5) << m[N - 1][M - cols + j];
    cout << "   <- последняя строка\n";
}

string pad(string s, int width)
{
    int len = 0;
    for (char c : s)
        if ((c & 0xC0) != 0x80) len++;
    while (len < width)
    {
        s += ' ';
        len++;
    }
    return s;
}

struct Result
{
    string name;
    long long comparisons;
    long long swaps;
    double ms;
};

Result run(int number, string name, int source[N][M], int method)
{
    static int m[N][M];
    memcpy(m, source, sizeof(m));
    comparisons = 0;
    swaps = 0;

    auto start = chrono::steady_clock::now();
    if (method == 1) bubbleSort(&m[0][0], TOTAL);
    if (method == 2) insertionSort(&m[0][0], TOTAL);
    if (method == 3) hoareSort(&m[0][0], 0, TOTAL - 1);
    auto finish = chrono::steady_clock::now();
    double ms = chrono::duration<double, milli>(finish - start).count();

    cout << "\n" << number << ") " << name << "\n";
    printPart(m, 3, 12);
    cout << "Сравнений:     " << comparisons << "\n";
    cout << "Перестановок:  " << swaps << "\n";
    cout << "Время:         " << fixed << setprecision(3) << ms << " мс\n";
    cout << "Отсортировано: " << (isSorted(m) ? "да" : "нет") << "\n";

    return { name, comparisons, swaps, ms };
}

int main()
{
    SetConsoleOutputCP(CP_UTF8);
    static int source[N][M];
    mt19937 gen(random_device{}());
    uniform_int_distribution<int> dist(-100, 100);
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            source[i][j] = dist(gen);

    cout << "Матрица " << N << " x " << M << " = " << TOTAL << " элементов, значения от -100 до 100\n\n";
    cout << "Исходная матрица:\n";
    printPart(source, 3, 12);

    Result r[3];
    r[0] = run(1, "Обычный (пузырёк)", source, 1);
    r[1] = run(2, "Вставка", source, 2);
    r[2] = run(3, "Хоара", source, 3);

    cout << "\nИтог:\n";
    cout << pad("Метод", 20) << pad("Сравнения", 14) << pad("Перестановки", 14) << "Время, мс\n";
    for (int i = 0; i < 3; i++)
    {
        cout << pad(r[i].name, 20) << pad(to_string(r[i].comparisons), 14) << pad(to_string(r[i].swaps), 14);
        cout << fixed << setprecision(3) << r[i].ms << "\n";
    }

    int best = 0;
    for (int i = 1; i < 3; i++)
        if (r[i].comparisons < r[best].comparisons) best = i;
    cout << "\nБыстрее всех: " << r[best].name << ", в " << r[0].comparisons / r[best].comparisons << " раз меньше сравнений, чем обычный\n";
    return 0;
}
