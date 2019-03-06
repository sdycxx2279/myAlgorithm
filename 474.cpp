//
//@author Xiao Xu
//@create 2019-03-04 21:10
//Ones and Zeroes
//dp算法，参考讨论区，一开始针对每个strs入选与否做dfs，但规模太大tl
//

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        for(string s : strs){
            vector<int> mn(2, 0);
            for(char c : s){
                if(c == '0')
                    mn[0]++;
                else
                    mn[1]++;

            }

            for(int i = m; i >= mn[0]; i--){
                for(int j = n; j >= mn[1]; j--){
                    dp[i][j] = max(dp[i - mn[0]][j - mn[1]] + 1, dp[i][j]);
                }
            }
        }

        return dp[m][n];
    }
};

int main(){
    Solution s;

    return 0;
}