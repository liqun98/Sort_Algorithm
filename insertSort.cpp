//
// Created by 赵立群 on 2021/10/20.
//
#include <algorithm>
#include <vector>
#include "sortAlgo.h"
using namespace std;

void insertSort(vector<int>& nums) {
    int size = nums.size();
    int current,prevIndex;
    for (int i = 1;i < size;i++) {
        prevIndex = i - 1;
        current = nums[i];
        while (prevIndex >= 0 && nums[prevIndex] > current) {
            nums[prevIndex+1] = nums[prevIndex];
            prevIndex--;
        }
        nums[prevIndex+1] = current;
    }
}
