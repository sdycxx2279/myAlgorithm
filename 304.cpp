//
//@author Xiao Xu
//@create 2018-11-19 21:10
//
//

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    NumMatrix(vector<vector<int>> matrix) {
        for(int i = 0; i < matrix.size(); i++){
            for(int j = 0; j < matrix[i].size(); j++){
                int a = i ? matrix[i - 1][j] : 0;
                int b = j ? matrix[i][j - 1]: 0;
                int c = i && j ? matrix[i-1][j-1] : 0;
                matrix[i][j] += (a + b - c);
                //cout<<matrix[i][j]<<" ";
            }
            //cout<<endl;
        }
        this->matrix = matrix;
    }

    int sumRegion(int row1, int col1, int row2, int col2) {
        int a = row1 ? matrix[row1 - 1][col2] : 0;
        int b = col1 ? matrix[row2][col1 - 1] : 0;
        int c = row1 && col1 ? matrix[row1 - 1][col1 - 1] : 0;
        return matrix[row2][col2] - a - b + c;
    }
private:
    vector<vector<int>> matrix;
};

int main(){
    Solution s;

    return 0;
}