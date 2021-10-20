//
// Created by 赵立群 on 2021/10/20.
//
#include <vector>
#include "sortAlgo.h"
using namespace std;

void buildHeap(vector<int>& nums, int parent, int length) {
    int child = parent*2 + 1;
    int tmp = nums[parent];
    while (child < length) {
        if (child + 1 < length && nums[child+1] > nums[child]) {
            child++;
        }
        if (nums[child] > tmp) {
            nums[parent] = nums[child];
            parent = child;
            child = parent*2 + 1;
        } else break;
    }
    nums[parent] = tmp;
}

void heapSort(vector<int>& nums) {
    for (int i = nums.size()/2 - 1;i >= 0;i--) {
        buildHeap(nums, i, nums.size());
    }

    for (int i = 0;i < nums.size();i++) {
        swap(nums[0], nums[nums.size()-1-i]);
        buildHeap(nums,0,nums.size()-1-i);
    }
}