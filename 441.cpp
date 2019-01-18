//
//@author Xiao Xu
//@create 2019-01-18 21:10
//Arranging Coins
//学习自讨论区，数学公式
//

#include<iostream>
#include<vector>
#include <cmath>

using namespace std;

class Solution {
public:
    int arrangeCoins(int n) {
        return (-1 + sqrt(1 + 8 * (long long)n)) / 2;
    }
};

int main(){
    Solution s;

    return 0;
}