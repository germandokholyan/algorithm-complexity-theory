#include "BubbleSort.h"

bool BubbleSort::compare(int a, int b)
{
    comparisons++;
    return a < b;
}

std::string BubbleSort::getName() const
{
    return "Обычный (пузырёк)";
}

std::vector<int> BubbleSort::sort(const std::vector<int>& source)
{
    std::vector<int> arr = source;
    int n = static_cast<int>(arr.size());
    for (int i = 0; i < n - 1; i++)
    {
        bool changed = false;
        for (int j = 0; j < n - 1 - i; j++)
        {
            if (compare(arr[j + 1], arr[j]))
            {
                int t = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = t;
                swaps++;
                changed = true;
            }
        }
        if (!changed)
            break;
    }
    return arr;
}

long long BubbleSort::getComparisons() const
{
    return comparisons;
}

long long BubbleSort::getSwaps() const
{
    return swaps;
}

void BubbleSort::resetStats()
{
    comparisons = 0;
    swaps = 0;
}
