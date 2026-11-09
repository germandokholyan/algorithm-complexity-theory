#include "InsertionSort.h"

bool InsertionSort::compare(int a, int b)
{
    comparisons++;
    return a < b;
}

int InsertionSort::findPlace(const std::vector<int>& sorted, int value)
{
    int low = 0;
    int high = static_cast<int>(sorted.size()) - 1;

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
    std::vector<int> sorted;

    for (int i = 0; i < static_cast<int>(arr.size()); i++)
    {
        int place = findPlace(sorted, arr[i]);
        swaps += static_cast<int>(sorted.size()) - place;
        sorted.insert(sorted.begin() + place, arr[i]);
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
