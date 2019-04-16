//
//@author Xiao Xu
//@create 2019-04-16 21:10
//Coin Change 2
//使用n种硬币组成n种钱，有多少种方法
//dp，假设我们不使用第i种硬币得到j块钱，有dp[i-1][j]种方法，使用的话有dp[i][j-coin[i]]种方法，相加即为dp[i][j]
//dp数组优化为1维如下

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int change(int amount, vector<int>& coins) {
        if(amount <= 0)
            return 1;
        if(!coins.size())
            return 0;
        vector<int> dp(amount + 1, 0);
        dp[0] = 1;
        for(int coin : coins){
            if(coin > amount)
                break;
            for(int i = coin; i <= amount; i++){
                dp[i] += dp[i - coin];
            }
        }
        return dp[amount];
    }
};

int main(){
    Solution s;

    return 0;
}