//
//@author Xiao Xu
//@create 2018-09-01 10:38
//Submission Detail
//分开判断而不是遍历整个数组可以有效较低算法复杂度
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();
        if(!m)
            return ;
        int n = matrix[0].size();
        if(!n)
            return ;
        bool row = false, column = false;
        if(!matrix[0][0]){
            row = true;
            column = true;
        }

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(!matrix[i][j] && i && j){
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }else if(!matrix[i][j] && !i){
                    row = true;
                }else if(!matrix[i][j] && !j){
                    column = true;
                }
            }
        }

        for(int i = m-1; i > 0; i--){
            for(int j = n-1; j > 0; j--){
                if(!matrix[i][0] || !matrix[0][j]){
                    matrix[i][j] = 0;
                }
            }
        }

        if(row){
            for(int i = 0; i < n; i++){
                matrix[0][i] = 0;
            }
        }
        if(column){
            for(int i = 0; i < m; i++){
                matrix[i][0] = 0;
            }
        }


    }
};

int main() {
    Solution s;

    return 0;
}
//void setZeroes(vector<vector<int>>& matrix) {
//    bool clearRow = false;
//    bool clearCol = false;
//
//    int rows = matrix.size();
//    int cols = matrix[0].size();
//
//    for(int j = 0; j < cols; j++) {
//        if(matrix[0][j] == 0) {
//            clearRow = true;
//            break;
//        }
//    }
//
//    for(int i = 0; i < rows; i++) {
//        if(matrix[i][0] == 0) {
//            clearCol = true;
//            break;
//        }
//    }
//
//    for(int i = 1; i < rows; i++) {
//        for(int j = 1; j < cols; j++) {
//            if(matrix[i][j] == 0) {
//                matrix[i][0] = 0;
//                matrix[0][j] = 0;
//            }
//        }
//    }
//
//    for(int i = 1; i < rows; i++) {
//        if(matrix[i][0] == 0) {
//            for(int j = 1; j < cols; j++) {
//                matrix[i][j] = 0;
//            }
//        }
//    }
//
//    for(int j = 1; j < cols; j++) {
//        if(matrix[0][j] == 0) {
//            for(int i = 1; i < rows; i++) {
//                matrix[i][j] = 0;
//            }
//        }
//    }
//
//    if(clearRow) {
//        for(int j = 0; j < cols; j++) {
//            matrix[0][j] = 0;
//        }
//    }
//
//
//    if(clearCol) {
//        for(int i = 0; i < rows; i++) {
//            matrix[i][0] = 0;
//        }
//    }
//}