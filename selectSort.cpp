//
// Created by 赵立群 on 2021/10/20.
//
#include <algorithm>
#include <vector>
#include "sortAlgo.h"
using namespace std;


void selectSort(vector<int>& nums){
    int size = nums.size(),minIndex;
    for (int i = 0;i < size - 1;i++) {
        minIndex = i;
        for (int j = i+1;j < size;j++) {
            if (nums[minIndex] > nums[j]) {
                minIndex = j;
            }
        }
        swap(nums[minIndex],nums[i]);
    }
}
