//
//@author Xiao Xu
//@create 2018-08-30 22:21
//Spiral Matrix II
//直接按顺序调整好就没必要在判断direction了,减少了多个判断操作
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> result(n, vector<int>(n, 0));
        if(!n)
            return result;

        //0代表上，1代表下，2代表左，3代表右
        int direction = 3, bottom = n - 1, top = 0, left = 0, right = n - 1, i = 0, j = 0, k = 1;
        while(top <= bottom && left <= right){
            if(direction == 0){
                while(i > top){
                    result[i--][j] = k++;
                }
                direction = 3;
                left++;
            }else if(direction == 1){
                while(i < bottom){
                    result[i++][j] = k++;
                }
                direction = 2;
                right--;
            }else if(direction == 2){
                while(j > left){
                    result[i][j--] = k++;
                }
                direction = 0;
                bottom--;
            }else{
                while(j < right){
                    result[i][j++] = k++;
                }
                direction = 1;
                top++;
            }
        }

        result[i][j] = k;
        return result;
    }
};

int main() {
    Solution s;

    return 0;
}
