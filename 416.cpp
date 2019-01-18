//
//@author Xiao Xu
//@create 2019-01-14 21:10
//Partition Equal Subset Sum
//学习自讨论区，动态规划
//

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        if(nums.empty())
            return false;
        int sum = 0;
        for(int num : nums){
            sum += num;
        }

        if(sum % 2)
            return false;
        sum /= 2;

        vector<bool> dp(sum + 1, false);
        dp[0] = true;

        for(int num : nums){
            for(int j = sum; j > 0; j--){
                if(j >= num)
                    dp[j] = (dp[j] || dp[j - num]);
            }
        }

        return dp[sum];
    }
};

int main(){
    Solution s;

    return 0;
}