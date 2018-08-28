//
//@author Xiao Xu
//@create 2018-08-28 22:15
//Counting Bits
//先初始化整个数组再修改比每次单独填充要稍快
//
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> result(num+1, 0);
        int binary = 1;

        for(int i = 1; i <= num; i++){
            int temp = i % binary;
            result[i] = result[temp] + 1;
            if(!temp)
                binary = i;
        }

        return result;
    }
};

int main() {
    Solution s;

    return 0;
}


//利用位运算实现思路
//抄了实现第一的算法，思路与我一致使用位运算实现，但只稍稍进步，排到13%，莫名其妙
//vector<int> countBits(int num) {
//    vector<int> dp(num + 1, 0);
//
//    for (int i = 1; i < num + 1; ++i) {
//        dp[i] = dp[i & (i - 1)] + 1;
//    }
//
//    return dp;
//}