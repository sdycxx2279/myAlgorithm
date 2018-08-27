//
//@author Xiao Xu
//@create 2018-08-27 21:30
//Spiral Matrix
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> result;
        if(matrix.empty())
            return result;
        int m = matrix.size();
        int n = matrix[0].size();

        //0代表上，1代表下，2代表左，3代表右
        int direction = 3;
        int bottom = m - 1;
        int top = 0;
        int left = 0;
        int right = n - 1;
        int i, j;
        i = j = 0;
        while(top <= bottom && left <= right){
            if(direction == 0){
                while(i > top){
                    result.push_back(matrix[i][j]);
                    i--;
                }
                direction = 3;
                left++;
            }else if(direction == 1){
                while(i < bottom){
                    result.push_back(matrix[i][j]);
                    i++;
                }
                direction = 2;
                right--;
            }else if(direction == 2){
                while(j > left){
                    result.push_back(matrix[i][j]);
                    j--;
                }
                direction = 0;
                bottom--;
            }else{
                while(j < right){
                    result.push_back(matrix[i][j]);
                    j++;
                }
                direction = 1;
                top++;
            }
        }
        result.push_back(matrix[i][j]);
        return result;
    }
};

int main() {
    Solution s;

    return 0;
}

