//
//@author Xiao Xu
//@create 2018-08-21 22:34
// Rotate Image
//先将方阵从上到下颠倒，再将其转置即可
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        for(int i = 0; i < matrix.size(); i++){
            int temp = matrix.size() - 1 - i;
            for(int j = 0; j < matrix.size(); j++){
                swap(matrix[i][j], matrix[temp][j]);
            }
        }

        for(int i = 0; i< matrix.size(); i++){
            for(int j = i + 1; j < matrix.size(); j++){
                swap(matrix[i][j], matrix[j][i]);
            }
        }
    }
};

int main() {
    Solution s;

    return 0;
}
