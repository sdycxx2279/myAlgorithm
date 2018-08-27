//
//@author Xiao Xu
//@create 2018-08-27 21:30
//Maximal Square
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int m = matrix.size();
        //使用empty大大增大了时间消耗
        if(!m)
            return 0;
        int n = matrix[0].size();
        vector<vector<int>> dp(m, vector<int>(n, 0));
        int max_size = 0;

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(matrix[i][j] == '1'){
                    //i&&j 比！（ i == 0 || j == 0） 快
                    if(i && j){
                        dp[i][j] = min(dp[i-1][j-1], min(dp[i-1][j], dp[i][j-1])) + 1;
                    }else{
                        dp[i][j] = 1;
                    }
                    max_size = max(max_size, dp[i][j]);
                }
            }
        }

        return max_size * max_size;
    }
};

int main() {
    Solution s;

    return 0;
}

//优化后版本
