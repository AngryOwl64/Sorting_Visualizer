#pragma once
#include <vector>
#include <iostream>
#include "SFML/Graphics.hpp"

namespace SortingAlgorithms {
    void bubbleSortStep(std::vector<int>& arr, int& i, int& j, bool& finished);
/*    void selectionSortStep(std::vector<int>& arr);
    void insertionSortStep(std::vector<int>& arr);
    void mergeSortStep(std::vector<int>& arr, int left, int right); */
    void bogoSortStep(std::vector<int>& arr, bool& finished);
}