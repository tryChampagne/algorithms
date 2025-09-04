#ifndef MY_FUNCTIONS_H
#define MY_FUNCTIONS_H

#include <vector>
#include <utility>

namespace MY_FUNCTIONS{
    std::pair<int,int> subArrayWithMaxSum(std::vector<int> &v);
    void selectionSort(std::vector<int> &v);
    void merge(std::vector<int> &v,int l,int mid,int h);
    void mergeSort(std::vector<int> &v,int l,int h);
}

#endif