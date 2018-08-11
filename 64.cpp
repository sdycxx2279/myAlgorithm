//
//@author Xiao Xu
//@create 2018-08-11 22:15
//Minimum Path Sum
//
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        if(m == 0)
            return 0;
        int n = grid[0].size();
        if(n == 0)
            return 0;

        vector<vector<int>> cur(m, vector<int>(n));
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(i == 0 && j == 0){
                    cur[i][j] = 0;
                }else if (i == 0 && j != 0){
                    cur[i][j] = cur[i][j - 1];
                }else if (i != 0 && j == 0){
                    cur[i][j] = cur[i - 1][j];
                }else{
                    cur[i][j] = min(cur[i - 1][j], cur[i][j - 1]);
                }
                cur[i][j] +=  grid[i][j];
            }
        }
        return cur[m-1][n-1];
    }
};

int main() {
    Solution s;

    return 0;
}
