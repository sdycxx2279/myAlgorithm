//
//@author Xiao Xu
//@create 2019-04-25 21:10
//Dungeon Game
//学习自讨论区，反向dp
//注意骑士生命值最小为1点，不可为0

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int m = dungeon.size();
        if(!m)
            return 0;
        int n = dungeon[0].size();
        if(!n)
            return 0;
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, INT_MAX));
        dp[m-1][n] = 1;
        dp[m][n-1] = 1;
        for(int i = m - 1; i >= 0; i--){
            for(int j = n - 1; j >= 0; j--){
                int need = min(dp[i+1][j], dp[i][j+1]) - dungeon[i][j];
                dp[i][j] = need > 0 ? need : 1;
            }
        }

        return dp[0][0];
    }
};

int main(){
    Solution s;

    return 0;
}