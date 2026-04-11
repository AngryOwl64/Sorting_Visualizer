#include <iostream>
#include "Algorithms.h"

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
}