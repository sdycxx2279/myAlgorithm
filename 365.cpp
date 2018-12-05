//
//@author Xiao Xu
//@create 2018-12-05 21:10
//Water and Jug Problem
//学习自讨论区，数学原理

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    bool canMeasureWater(int x, int y, int z) {
        if(x + y < z)
            return false;
        if(z == x || z == y || z == x + y)
            return true;
        return !(z % getMeasure(x, y));
    }

    int getMeasure(int a, int b){
        while(b != 0){
            int temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }
};

int main(){
    Solution s;

    return 0;
}