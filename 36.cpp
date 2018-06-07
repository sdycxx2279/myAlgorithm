//
//@author Xiao Xu
//@create 2018-06-07 10:05
//Valid Sudoku
//暴力遍历行、列与九宫格
//

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for(int i = 0; i < 9; i++){
            unordered_map<char,int> row;
            for(int j = 0; j < 9; j++){
                if(board[i][j] != '.'){
                    if(row.count(board[i][j]) == 0){
                        row[board[i][j]] = 1;
                    }else{
                        return false;
                    }
                }
            }
        }

        //判断列
        for(int i = 0; i < 9; i++){
            unordered_map<char,int> column;
            for(int j = 0; j < 9; j++){
                if(board[j][i] != '.'){
                    if(column.count(board[j][i]) == 0){
                        column[board[j][i]] = 1;
                    }else{
                       return false;
                    }
                }
            }
        }

        //判断九宫格
        for(int i = 0; i < 9; i++){
            int row_sub = i / 3 * 3;
            int column_sub = i % 3 * 3;
            unordered_map<char,int> sub;
            for(int j = 0; j < 9; j++){
                int row = row_sub + j / 3;
                int column = column_sub + j % 3;
                if(board[row][column] != '.'){
                    if(sub.count(board[row][column]) == 0){
                        sub[board[row][column]] = 1;
                    }else{
                        return false;
                    }
                }
            }
        }
        return true;
    }
};

int main() {
    Solution s;
    return 0;
}

//checkrow = {1,2,3,4,5,6,7,8,9};
//if (checkrow[board[i][j] - '1'] == board[i][j] - '0') {
//checkrow[board[i][j] - '1'] = 0;
//} else {
//return false;
//}