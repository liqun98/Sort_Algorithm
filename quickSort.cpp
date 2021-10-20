//
// Created by 赵立群 on 2021/10/20.
//
#include <vector>
#include <algorithm>
#include "sortAlgo.h"
using namespace std;

int partition(vector<int>& nums,int start,int end) {
    int pValue = nums[start];
    int left = start, right = end;
    while (true) {
        while (left <= right && nums[left] <= pValue) {
            left++;
        }

        while (left <= right && nums[right] > pValue) {
            right--;
        }

        if (left >= right)break;
        swap(nums[left],nums[right]);
    }
    swap(nums[right], nums[start]);
    return right;
}


void quickSort(vector<int>& nums, int start, int end) {
    if (end<=start) return;
    int pIndex = partition(nums, start, end);
    quickSort(nums, start, pIndex - 1);
    quickSort(nums, pIndex + 1, end);
}

void quickSort(vector<int>& nums) {
    quickSort(nums,0,nums.size()-1);
}



