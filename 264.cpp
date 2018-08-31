//
//@author Xiao Xu
//@create 2018-08-30 22:22
//Ugly Number II
//按讨论区思想实现代码
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> dp(n, 1);

        int j = 0, k = 0, l = 0;
        for(int i = 1; i < n; i++){
            dp[i] = min(dp[j] * 2, min(dp[k] * 3, dp[l] * 5));

            if(dp[i] == dp[j] * 2)
                j++;
            if(dp[i] == dp[k] * 3)
                k++;
            if(dp[i] == dp[l] * 5)
                l++;
        }

        return dp[n-1];
    }
};

int main() {
    Solution s;

    return 0;
}
