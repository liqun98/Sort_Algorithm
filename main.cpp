#include <iostream>
#include <vector>
#include "sortAlgo.h"
#include <random>
using namespace  std;

class RandomArray{
private:
    vector<int> arr;
public:
    RandomArray(){
        random_device rd;
        mt19937 mt(rd());
        uniform_int_distribution<> dist(1, 100);
        for(int i = 0;i < 10;i++){
            arr.push_back(dist(mt));
        }
    }

    vector<int>& getArray(){
        return arr;
    }

    void printArr(){
        for(auto c: arr) {
            cout << c << " ";
        }
        cout << endl;
    }

    bool isSorted(){
        for (int i = 0;i < arr.size() - 1;i++) {
            if (arr[i] > arr[i+1]) {
                return false;
            }
        }
        return true;
    }
};

bool test(int times, void (*pf)(vector<int>&)) {
    bool res = true;
    for (int i = 0;i < times;i++) {
        RandomArray a;
        pf(a.getArray());
        a.printArr();
        res = res && a.isSorted();
    }
    return res;
}

int lc(vector<int> nums, int target) {
    const int sum = accumulate(nums.begin(),nums.end(),0);
    vector<bool> can(sum+1, false);
    can[0] = true;
    for (auto num: nums) {
        can[num] = true;
    }
    for (auto num: nums) {
        for (int i = sum;i >= num;i--) {
            can[i] = can[i] || can[i-num];
        }
    }
    for (int i = target;i <= sum;i++) {
        if (can[i]) {
            return i;
        }
    }
    return 0;
}


int main() {
    cout << lc(vector<int>{25,5,80,30,120},100);
    return EXIT_SUCCESS;
}
