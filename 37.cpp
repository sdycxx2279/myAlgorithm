//
//@author Xiao Xu
//@create 2018-06-08 19:46
//Sudoku Solver
//问题1：判断九宫格出错；问题2：循环遍历棋盘时，忘记重置j = 0。
//

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        solveOne(board, 0, 0);
    }

    bool solveOne(vector<vector<char>>& board, int x, int y){
        if(x == 9)
            return true;
        for(int i = x; i < 9; i++){
            for(int j = y; j < 9; j++){
                if(board[i][j] == '.'){
                    for(int k = 1; k < 10; k++){
                        board[i][j] = '0' + k;
                        if(isValid(board, i, j)){
                            int temp_i = i;
                            int temp_j = j;
                            if(j < 8)
                                j++;
                            else{
                                i++;
                                j = 0;
                            }
                            vector<vector<char>> now_board = board;
                            if(solveOne(board, i, j)){
                                return true;
                            }
                            i = temp_i;
                            j = temp_j;
                            board = now_board;
                        }
                    }
                    return false;
                }
            }
            y = 0;
        }
        return true;
    }

    bool isValid(vector<vector<char>>& board, int x, int y){
        int x_sub_begin = x / 3 * 3;
        int y_sub_begin = y / 3 * 3;
        unordered_map<char,int> row;
        unordered_map<char,int> column;
        unordered_map<char,int> sub;
        for(int i = 0; i < 9; i++){
            if(board[x][i] != '.'){
                if(row.count(board[x][i]) == 0){
                    row[board[x][i]] = 1;
                }else{
                    return false;
                }
            }

            if(board[i][y] != '.'){
                if(column.count(board[i][y]) == 0){
                    column[board[i][y]] = 1;
                }else{
                    return false;
                }
            }

            int x_sub = x_sub_begin + i / 3;
            int y_sub = y_sub_begin + i % 3;
            if(board[x_sub][y_sub] != '.'){
                if(sub.count(board[x_sub][y_sub]) == 0){
                    sub[board[x_sub][y_sub]] = 1;
                }else{
                    return false;
                }
            }
        }
        return true;
    }
};

int main() {
    Solution s;
    vector<char> c1 = {'5', '3', '.', '.', '7', '.', '.', '.', '.'};
    vector<char> c2 = {'6','.','.','1','9','5','.','.','.'};
    vector<char> c3 = {'.','9','8','.','.','.','.','6','.'};
    vector<char> c4 = {'8','.','.','.','6','.','.','.','3'};
    vector<char> c5 = {'4','.','.','8','.','3','.','.','1'};
    vector<char> c6 = {'7','.','.','.','2','.','.','.','6'};
    vector<char> c7 = {'.','6','.','.','.','.','2','8','.'};
    vector<char> c8 = {'.','.','.','4','1','9','.','.','5'};
    vector<char> c9 = {'.','.','.','.','8','.','.','7','9'};

    vector<vector<char>> c;
    c.push_back(c1);
    c.push_back(c2);
    c.push_back(c3);
    c.push_back(c4);
    c.push_back(c5);
    c.push_back(c6);
    c.push_back(c7);
    c.push_back(c8);
    c.push_back(c9);

    s.solveSudoku(c);
    return 0;
}
