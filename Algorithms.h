#pragma once
#include <vector>

namespace SortingAlgorithms {
    void bubbleSortStep(std::vector<int>& arr);
    void selectionSortStep(std::vector<int>& arr);
    void insertionSortStep(std::vector<int>& arr);
    void mergeSortStep(std::vector<int>& arr, int left, int right);
    void bogoSortStep(std::vector<int>& arr)
}