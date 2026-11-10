#include "InsertionSort.h"

bool InsertionSort::compare(int a, int b)
{
    comparisons++;
    return a < b;
}

int InsertionSort::findPlace(const std::vector<int>& sorted, int count, int value)
{
    int low = 0;
    int high = count - 1;

    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (compare(value, sorted[mid]))
            high = mid - 1;
        else
            low = mid + 1;
    }

    return low;
}

std::string InsertionSort::getName() const
{
    return "Вставка";
}

std::vector<int> InsertionSort::sort(const std::vector<int>& arr)
{
    int n = static_cast<int>(arr.size());
    std::vector<int> sorted(n);
    int count = 0;

    for (int i = 0; i < n; i++)
    {
        int place = findPlace(sorted, count, arr[i]);
        for (int j = count; j > place; j--)
        {
            sorted[j] = sorted[j - 1];
            swaps++;
        }
        sorted[place] = arr[i];
        count++;
    }

    return sorted;
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
