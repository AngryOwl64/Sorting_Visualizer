#include <iostream>
#include "Algorithms.h"

bool isSorted(std::vector<int>& arr) {
    for (size_t i = 0; i < arr.size() - 1; ++i) {
        if (arr[i] > arr[i + 1]) return 0;
    } return 1;
}

namespace SortingAlgorithms {

    void bubbleSortStep(std::vector<int>& arr, int& i, int& j, bool& finished) {
        int n = arr.size();

        if (finished) return;

        if (arr[j] > arr[j + 1]) {
            std::swap(arr[j], arr[j + 1]);
        }

        j++;

        if (j >= n - i - 1) {
            j = 0;
            i++;
        }

        if (i >= n - 1) {
            finished = true;
        }
    }
    void bogoSortStep(std::vector<int>& arr, bool& finished) {
        if (finished || arr.size() < 2) return;
        
        int i = rand() % arr.size();
        int j = rand() % arr.size();

        std::swap(arr[i], arr[j]);

        finished = isSorted(arr);
    }
}