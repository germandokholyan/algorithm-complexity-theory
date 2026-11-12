#include "HoareSort.h"

bool HoareSort::compare(int a, int b)
{
    comparisons++;
    return a < b;
}

std::vector<int> HoareSort::quickSort(const std::vector<int>& arr)
{
    if (arr.size() <= 1)
        return arr;

    int middle = static_cast<int>(arr.size()) / 2;
    int pivot = arr[middle];

    std::vector<int> left;
    std::vector<int> right;

    for (int i = 0; i < static_cast<int>(arr.size()); i++)
    {
        if (i == middle)
            continue;

        if (compare(pivot, arr[i]))
            right.push_back(arr[i]);
        else
            left.push_back(arr[i]);
        swaps++;
    }

    std::vector<int> result = quickSort(left);
    std::vector<int> rightSorted = quickSort(right);

    result.push_back(pivot);
    for (int i = 0; i < static_cast<int>(rightSorted.size()); i++)
        result.push_back(rightSorted[i]);

    return result;
}

std::string HoareSort::getName() const
{
    return "Хоара";
}

std::vector<int> HoareSort::sort(const std::vector<int>& arr)
{
    return quickSort(arr);
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
