//
//@author Xiao Xu
//@create 2019-04-17 11:10
//Palindrome Partitioning II
//将一整个字符串切分为若干个回文字符串最少需要切几次
//遍历整个字符串，看以其为中心的回文串，利用该回文串头的dp值更新其尾部的dp值

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int minCut(string s) {
        vector<int> dp(s.size() + 1, 0);
        for(int i = 0; i < dp.size(); i++){
            dp[i] = i - 1;
        }
        for(int i = 0; i < s.size(); i++){
            for(int j = 0; i - j >= 0 && i + j < s.size() && s[i-j] == s[i + j];j++){
                dp[i + j + 1] = min(dp[i + j + 1], dp[i - j] + 1);
            }
            for(int j = 0; i - j  - 1 >= 0 && i + j < s.size() && s[i- j - 1] == s[i + j];j++){
                dp[i + j + 1] = min(dp[i + j + 1], dp[i - j - 1] + 1);
            }
        }

        return dp[s.size()];
    }
};

int main(){
    Solution s;

    return 0;
}