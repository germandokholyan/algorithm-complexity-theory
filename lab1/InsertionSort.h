#ifndef INSERTIONSORT_H
#define INSERTIONSORT_H

#include <vector>
#include <string>

class InsertionSort
{
private:
    long long comparisons = 0;
    long long swaps = 0;
    bool compare(int a, int b);
    int findPlace(const std::vector<int>& sorted, int count, int value);

public:
    std::string getName() const;
    std::vector<int> sort(const std::vector<int>& arr);
    long long getComparisons() const;
    long long getSwaps() const;
    void resetStats();
};

#endif
