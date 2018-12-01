//
//@author Xiao Xu
//@create 2018-11-18 13:59
//Game of Life
//
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        this->board = board;
        for(int i = 0; i < board.size(); i++){
            for(int j = 0; j < board[i].size(); j++){
                int live = getNeighbor(i, j);
                if(!board[i][j] && live == 3)
                    board[i][j] = 10;
                else if(board[i][j] && live <= 3 && live >=2)
                    board[i][j] = 11;
            }
        }
        for(int i = 0; i < board.size(); i++){
            for(int j = 0; j < board[i].size(); j++){
                board[i][j] /= 10;
            }
        }
    }

    int getNeighbor(int i, int j){
        int live = 0;
        int row_begin, row_end, col_begin, col_end;
        row_begin = !i ? i : i - 1;
        row_end = i == this->board.size() - 1 ? i : i + 1;
        col_begin = !j ? j : j - 1;
        col_end = j == this->board[0].size() - 1 ? j : j + 1;
        for(int k = row_begin; k <= row_end; k++){
            for(int l = col_begin; l <= col_end; l++){

                if(this->board[k][l] % 10)
                    live++;
            }
        }

        if(board[i][j])
            live--;
        return live;
    }
private:
    vector<vector<int>> board;
};

int main() {
    Solution s;

    return 0;
}
