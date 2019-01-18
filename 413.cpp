//
//@author Xiao Xu
//@create 2019-01-14 21:10
//Arithmetic Slices
//
//

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& A) {
        if(A.size() < 3)
            return 0;
        vector<int> diff(A.size(), 0);
        vector<int> nums(A.size(), 0);

        for(int i = 1; i < A.size(); i++){
            diff[i] = A[i] - A[i - 1];
        }

        int length = 2;
        for(int i = 2; i < diff.size(); i++){
            if(diff[i] == diff[i - 1]){
                length++;
                nums[i] = nums[i - 1] + 1;
            }else
                length = 2;
        }

        int res = 0;
        for(int num : nums){
            res += num;
        }
        return res;
    }
};

int main(){
    Solution s;

    return 0;
}