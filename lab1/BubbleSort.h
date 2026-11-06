#ifndef BUBBLESORT_H
#define BUBBLESORT_H

#include <vector>
#include <string>

class BubbleSort
{
private:
    long long comparisons = 0;
    long long swaps = 0;
    bool compare(int a, int b);

public:
    std::string getName() const;
    void sort(std::vector<int>& arr);
    long long getComparisons() const;
    long long getSwaps() const;
    void resetStats();
};

#endif
