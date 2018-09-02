//
//@author Xiao Xu
//@create 2018-09-01 10:38
//
//
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();
        if(!m)
            return;
        int n = matrix[0].size();

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(!matrix[i][j]){
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }


    }
};

int main() {
    Solution s;

    return 0;
}
