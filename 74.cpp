//
//@author Xiao Xu
//@create 2018-09-04 22:26
//Submission Detail
//
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(!matrix.size() || !matrix[0].size())
            return false;

        int left = 0, right = matrix.size() - 1;
        while(left < right){
            int middle = (left + right) / 2;
            if(matrix[middle][0] == target)
                return true;
            else if(matrix[middle][0] < target)
                left = middle + 1;
            else
                right = middle - 1;
        }

        int i;
        if(matrix[left][0] > target){
            if(left)
                i = left - 1;
            else
                return false;
        }
        else
            i = left;
        left = 0;
        right = matrix[0].size() - 1;
        while(left <= right){
            int middle = (left + right) / 2;
            if(matrix[i][middle] == target)
                return true;
            else if(matrix[i][middle] < target)
                left = middle + 1;
            else
                right = middle - 1;
        }
        return false;
    }
};

int main() {
    Solution s;

    return 0;
}
//
//int i=0, j = col-1;
//while(0<=j&&row>i)
//{
//if(target==matrix[i][j])
//{
//return true;
//}
//else if(target>matrix[i][j])
//{
//++i;
//}
//else
//{
//--j;
//}
//}