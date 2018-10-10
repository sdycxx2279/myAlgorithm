//
//@author Xiao Xu
//@create 2018-10-09 22:33
//Number of Islands
//bfs似乎更省时间？
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int result = 0;
        int m = grid.size();
        if(!m)
            return 0;
        int n = grid[0].size();
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                result += dfs(grid, i, j);
            }
        }

        return result;
    }

    int dfs(vector<vector<char>>& grid, int i, int j){
        if(grid[i][j] == '1'){
            grid[i][j] = '#';
            int m = grid.size(), n = grid[0].size();
            if(i != 0)
                dfs(grid, i - 1, j);
            if(i != m - 1)
                dfs(grid, i + 1, j);
            if(j != 0)
                dfs(grid, i, j - 1);
            if(j !=  n - 1)
                dfs(grid, i, j + 1);
            return 1;
        }
        return 0;
    }
};

int main() {
    Solution s;

    return 0;
}
//void set_zero(vector<vector<char>>& grid, int i, int j){
//    if(i<0 || j<0 || i>=grid.size() || j>=grid[0].size() || grid[i][j] == '0')
//        return;
//    grid[i][j] = '0';
//    //left
//    set_zero(grid, i, j-1);
//    //right
//    set_zero(grid, i, j+1);
//    //down
//    set_zero(grid, i+1, j);
//    //up
//    set_zero(grid, i-1, j);
//}