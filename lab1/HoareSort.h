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
    std::vector<int> quickSort(const std::vector<int>& arr);

public:
    std::string getName() const;
    std::vector<int> sort(const std::vector<int>& arr);
    long long getComparisons() const;
    long long getSwaps() const;
    void resetStats();
};

#endif
