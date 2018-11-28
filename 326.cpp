//
//@author Xiao Xu
//@create 2018-11-28 21:10
//Power of Three
//任何int范围内3的次幂数一定能整除int范围内3的最大次幂

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    bool isPowerOfThree(int n) {
        return (n > 0 && 1162261467 % n == 0);
    }
};

int main(){
    Solution s;

    return 0;
}