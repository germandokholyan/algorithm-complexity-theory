#include "BubbleSort.h"
#include "InsertionSort.h"
#include "HoareSort.h"

#include <iostream>
#include <iomanip>
#include <random>
#include <chrono>
#include <locale.h>

using namespace std;

const int ROWS = 100;
const int COLS = 100;

vector<int> createMatrix(int minValue, int maxValue)
{
    vector<int> matrix(ROWS * COLS);
    mt19937 gen(random_device{}());
    uniform_int_distribution<int> dist(minValue, maxValue);

    for (int i = 0; i < ROWS * COLS; i++)
        matrix[i] = dist(gen);

    return matrix;
}

void printMatrix(const vector<int>& matrix, int rows, int cols)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
            cout << setw(5) << matrix[i * COLS + j];
        cout << "  ...\n";
    }
    cout << "  ...\n";
}

bool checkSorted(const vector<int>& arr)
{
    for (size_t i = 1; i < arr.size(); i++)
        if (arr[i] < arr[i - 1])
            return false;
    return true;
}

template <typename T>
double test(T& sorter, const vector<int>& matrix)
{
    vector<int> arr = matrix;
    sorter.resetStats();

    auto start = chrono::high_resolution_clock::now();
    sorter.sort(arr);
    auto end = chrono::high_resolution_clock::now();
    double ms = chrono::duration<double, milli>(end - start).count();

    cout << "\n" << sorter.getName() << ":\n";
    printMatrix(arr, 2, 12);
    cout << "Сравнений:     " << sorter.getComparisons() << '\n';
    cout << "Перестановок:  " << sorter.getSwaps() << '\n';
    cout << "Время:         " << fixed << setprecision(3) << ms << " мс\n";
    cout << "Отсортировано: " << (checkSorted(arr) ? "да" : "нет") << '\n';

    return ms;
}

int main()
{
    setlocale(LC_ALL, "RU");

    const int a = -100;
    const int b = 100;

    vector<int> matrix = createMatrix(a, b);

    cout << "Матрица " << ROWS << " x " << COLS << " = " << ROWS * COLS
        << " элементов, диапазон: [" << a << "; " << b << "]\n\n";
    cout << "Исходная матрица:\n";
    printMatrix(matrix, 3, 12);

    BubbleSort bubble;
    InsertionSort insertion;
    HoareSort hoare;

    double bubbleTime = test(bubble, matrix);
    double insertionTime = test(insertion, matrix);
    double hoareTime = test(hoare, matrix);

    cout << "\nИтог:\n";
    cout << left << setw(20) << "Метод" << setw(14) << "Сравнения" << setw(14) << "Перестановки" << "Время, мс\n";
    cout << setw(20) << bubble.getName() << setw(14) << bubble.getComparisons() << setw(14) << bubble.getSwaps() << bubbleTime << '\n';
    cout << setw(20) << insertion.getName() << setw(14) << insertion.getComparisons() << setw(14) << insertion.getSwaps() << insertionTime << '\n';
    cout << setw(20) << hoare.getName() << setw(14) << hoare.getComparisons() << setw(14) << hoare.getSwaps() << hoareTime << '\n';

    cout << "\nБыстрее всех: ";
    if (hoareTime <= insertionTime && hoareTime <= bubbleTime)
        cout << hoare.getName() << '\n';
    else if (insertionTime <= bubbleTime)
        cout << insertion.getName() << '\n';
    else
        cout << bubble.getName() << '\n';

    return 0;
}
