//
//@author Xiao Xu
//@create 2018-09-14 15:34
// Surrounded Regions
//忘记处理[]
//不再新建标记矩阵，直接将全部不要反转的'O'置为'*'，第二次遍历翻转全部’O'并将'*'置为'O'即可
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int m = board.size();
        if(!m)
            return ;
        int n= board[0].size();
        vector<vector<bool>> board_flip(m, vector<bool>(n, false));
        for(int i = 0; i < n; i++){
            dfs(board, board_flip, 0, i);
            dfs(board, board_flip, m - 1, i);
        }

        for(int i = 1; i < m - 1; i++){
            dfs(board, board_flip, i, 0);
            dfs(board, board_flip, i, n - 1);
        }

        for(int i = 1; i < m - 1; i++){
            for(int j = 1; j < n - 1; j++){
                if(!board_flip[i][j])
                    board[i][j] = 'X';
            }
        }
    }

    void dfs(vector<vector<char>>& board, vector<vector<bool>>& board_flip, int i, int j){
        if(!board_flip[i][j] && board[i][j] == 'O'){
            int m = board.size();
            int n= board[0].size();
            board_flip[i][j] = true;
            if(i > 0)
                dfs(board, board_flip, i - 1, j);
            if(i < m - 1)
                dfs(board, board_flip, i + 1, j);
            if(j > 0)
                dfs(board, board_flip, i,  j - 1);
            if(j < n - 1)
                dfs(board, board_flip, i, j + 1);
        }
    }
};

int main() {
    Solution s;

    return 0;
}
