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


int main() {
    cout << (test(10, quickSort) ? "valid" : "invalid") << endl;
    return EXIT_SUCCESS;
}
