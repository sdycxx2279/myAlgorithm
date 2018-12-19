//
//@author Xiao Xu
//@create 2018-12-19 21:10
//Kth Smallest Element in a Sorted Matrix
//基于index的折半查找
//

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int lo = matrix[0][0], hi = matrix[matrix.size() - 1][matrix[0].size() - 1] + 1;

        while(lo < hi){
            int count = 0, mid = lo + (hi - lo) / 2;
            for(int i = 0; i < matrix.size(); i++){
                int temp = 0;
                for(int j = 0; j < matrix[i].size() && matrix[i][j] <= mid; j++){
                    temp++;
                }
                count += temp;
            }
            if(count < k)
                lo = mid + 1;
            else
                hi = mid;

        }
        return lo;
    }
};

int main(){
    Solution s;

    return 0;
}