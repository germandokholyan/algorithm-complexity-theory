#include "HoareSort.h"

bool HoareSort::compare(int a, int b)
{
    comparisons++;
    return a < b;
}

void HoareSort::quickSort(std::vector<int>& arr, int left, int right)
{
    int i = left;
    int j = right;
    int pivot = arr[(left + right) / 2];

    while (i <= j)
    {
        while (compare(arr[i], pivot))
            i++;
        while (compare(pivot, arr[j]))
            j--;
        if (i <= j)
        {
            int t = arr[i];
            arr[i] = arr[j];
            arr[j] = t;
            swaps++;
            i++;
            j--;
        }
    }

    if (left < j)
        quickSort(arr, left, j);
    if (i < right)
        quickSort(arr, i, right);
}

std::string HoareSort::getName() const
{
    return "Хоара";
}

void HoareSort::sort(std::vector<int>& arr)
{
    if (arr.size() > 1)
        quickSort(arr, 0, static_cast<int>(arr.size()) - 1);
}

long long HoareSort::getComparisons() const
{
    return comparisons;
}

long long HoareSort::getSwaps() const
{
    return swaps;
}

void HoareSort::resetStats()
{
    comparisons = 0;
    swaps = 0;
}
