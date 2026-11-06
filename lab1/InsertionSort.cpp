#include "InsertionSort.h"

bool InsertionSort::compare(int a, int b)
{
    comparisons++;
    return a < b;
}

std::string InsertionSort::getName() const
{
    return "Вставка";
}

void InsertionSort::sort(std::vector<int>& arr)
{
    int n = static_cast<int>(arr.size());
    for (int i = 1; i < n; i++)
    {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && compare(key, arr[j]))
        {
            arr[j + 1] = arr[j];
            swaps++;
            j--;
        }
        arr[j + 1] = key;
    }
}

long long InsertionSort::getComparisons() const
{
    return comparisons;
}

long long InsertionSort::getSwaps() const
{
    return swaps;
}

void InsertionSort::resetStats()
{
    comparisons = 0;
    swaps = 0;
}
