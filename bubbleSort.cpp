//
// Created by 赵立群 on 2021/10/20.
//
#include <algorithm>
#include <vector>
#include "sortAlgo.h"
using namespace std;


void bubbleSort(vector<int>& nums){
    int size = nums.size();
    for (int i = size - 1;i >= 1;i--) {
        for (int j = 0;j < i;j++) {
            if (nums[j]  > nums[j+1]) {
                swap(nums[j],nums[j+1]);
            }
        }
    }
}

