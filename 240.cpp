//
//@author Xiao Xu
//@create 2018-10-23 20:58
//Search a 2D Matrix II
//该矩阵中值永远比左上大，比右下小，可以利用这一点，从右上方开始，若值比目标小，则向左，否则向下

#include<iostream>
using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int> >& matrix, int target) {
        for(int i = 0; i < matrix.size(); i++){
            int left = 0, right = matrix[i].size() - 1;
            while(left <= right){
                int mid = (left + right) / 2;
                if(matrix[i][mid] == target)
                    return true;
                else if(matrix[i][mid] < target)
                    left = mid + 1;
                else
                    right = mid - 1;
            }
        }

        return false;
    }

//    int col = c-1, row = 0;
//
//    while(col >= 0 && row < r )
//    {
//        if(matrix[row][col] == target)
//            return true;
//        else if(matrix[row][col] < target)
//            row++;
//        else
//            col--;
//    }
//    return false;
};

int main(){
    Solution s;

    return 0;
}



