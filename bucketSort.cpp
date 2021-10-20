//
// Created by 赵立群 on 2021/10/20.
//
#include <vector>
#include <algorithm>
#include "sortAlgo.h"
using namespace std;

void bucketSort(vector<int>& nums) {
    int max_value = *max_element(nums.begin(),nums.end());
    int min_value = *min_element(nums.begin(),nums.end());

    const int DEFAULT_BUCKET_SIZE = 5;
    const int bucketCount = (max_value-min_value)/DEFAULT_BUCKET_SIZE + 1;
    vector<vector<int>> bucket(bucketCount);

    for (int i = 0; i < nums.size(); i++) {
        bucket[(nums[i] - min_value) / DEFAULT_BUCKET_SIZE].push_back(nums[i]);
    }

    int sortIndex = 0;
    for (int i = 0;i < bucketCount;i++) {
        insertSort(bucket[i]);
        for (int j = 0;j < bucket[i].size();j++) {
            nums[sortIndex++] = bucket[i][j];
        }
    }
}


