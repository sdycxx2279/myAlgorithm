//
//@author Xiao Xu
//@create 2019-04-11 21:10
//Distinct Subsequences
//对字符串s，t，给出s中有多少个子序列等于t
//dp，dp[i][j] = dp[i-1][j] + (s[i] == t[j])(dp[i-1][j-1])
//需要使用long，不然无法处理部分用例

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int numDistinct(string s, string t) {
        vector<long> dp(t.size() + 1, 0);
        dp[0] = 1;
        int last = 0;
        for(int i = 1; i <= s.size(); i++){
            last = dp[0];
            for(int j = 1; j <= t.size(); j++){
                int temp = dp[j];
                if(s[i - 1] == t[j - 1]){
                    dp[j] = dp[j] + last;
                }
                last = temp;
            }
        }
        return dp[t.size()];
    }
};

int main(){
    Solution s;

    return 0;
}