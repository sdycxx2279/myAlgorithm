//
//@author Xiao Xu
//@create 2018-08-14 23:57
//Unique Paths II
//忘记处理边缘障碍点
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        if(m <= 0)
            return 0;
        int n = obstacleGrid[0].size();
        if(n <= 0)
            return 0;
        vector<int> cur(n, 0);
        cur[0] = 1;

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(obstacleGrid[i][j] == 1)
                    cur[j] = 0;
                else if(j > 0)
                    cur[j] += cur[j-1];
            }
        }

        return cur[n-1];
    }
};

int main() {
    Solution s;
    vector<vector<int>> v = {{0,1,0,0,0},{1,0,0,0,0},{0,0,0,0,0},{0,0,0,0,0}};
    cout<<s.uniquePathsWithObstacles(v);
    return 0;
}
