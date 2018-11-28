//
//@author Xiao Xu
//@create 2018-11-20 21:10
//Best Time to Buy and Sell Stock with Cooldown
//学习自讨论区，画出一个有限状态自动机，问题可解

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size() <= 1)
            return 0;

        vector<int> s1(prices.size(), 0);
        vector<int> s2(prices.size(), 0);
        vector<int> s3(prices.size(), 0);
        s1[0] = 0;
        s2[0] = -prices[0];
        s3[0] = INT_MIN;

        for(int i = 1; i < prices.size(); i++){
            s1[i] = max(s1[i - 1], s3[i - 1]);
            s2[i] = max(s2[i - 1], s1[i - 1] - prices[i]);
            s3[i] = s2[i - 1] + prices[i];
        }

        return max(s1[prices.size() - 1], s3[prices.size() - 1]);
    }
};

int main(){
    Solution s;

    return 0;
}