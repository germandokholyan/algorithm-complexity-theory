#ifndef HOARESORT_H
#define HOARESORT_H

#include <vector>
#include <string>

class HoareSort
{
private:
    long long comparisons = 0;
    long long swaps = 0;
    bool compare(int a, int b);
    void quickSort(std::vector<int>& arr, int left, int right);

public:
    std::string getName() const;
    void sort(std::vector<int>& arr);
    long long getComparisons() const;
    long long getSwaps() const;
    void resetStats();
};

#endif
