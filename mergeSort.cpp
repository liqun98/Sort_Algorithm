//
// Created by 赵立群 on 2021/10/20.
//
#include <vector>
#include "sortAlgo.h"
using namespace std;

void merge(vector<int>& nums,vector<int>& tmp,int start,int mid,int end) {
    for (int i = start;i <= end;i++) {
        tmp[i] = nums[i];
    }

    int left = start, right = mid+1, flag = start;
    while(left <= mid && right <= end) {
        if (tmp[left] <= tmp[right]) {
            nums[flag++] = tmp[left++];
        } else {
            nums[flag++] = tmp[right++];
        }
    }
    while (left <= mid) {
        nums[flag++] = tmp[left++];
    }
    while (right <= end) {
        nums[flag++] = tmp[right++];
    }
}

void mergeSort(vector<int>& nums,vector<int>& tmp,int start,int end) {
    if (end <= start) return;
    int mid = (start + end) / 2;
    mergeSort(nums,tmp,start,mid);
    mergeSort(nums,tmp,mid+1,end);

    merge(nums,tmp,start,mid,end);
}

void mergeSort(vector<int>& nums) {
    vector<int>tmp(nums.size());
    mergeSort(nums, tmp, 0, nums.size() - 1);
}

