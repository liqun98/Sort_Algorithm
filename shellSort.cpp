//
// Created by 赵立群 on 2021/10/20.
//
#include <vector>
#include "sortAlgo.h"
using namespace std;

void shellSort(vector<int>& nums){
    int gap = 1, size = nums.size(),temp;
    while (gap < size/3) {
        gap = gap*3 + 1;
    }
    for (;gap > 0;gap /= 3) {
        for (int i = gap;i < size;i++) {
            temp = nums[i];
            int j = i - gap;
            for (;j >= 0 && nums[j] > temp;j -= gap) {
                nums[j+gap] = nums[j];
            }
            nums[j+gap] = temp;
        }
    }
}

