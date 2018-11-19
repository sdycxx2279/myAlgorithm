//
//@author Xiao Xu
//@create 2018-11-19 21:10
//Range Sum Query - Immutable
//

#include<iostream>
#include<vector>
using namespace std;



class NumArray {
public:
    NumArray(vector<int> nums) {
        for(int i = 1; i < nums.size(); i++){
            nums[i] += nums[i - 1];
        }
        this->nums = nums;
    }

    int sumRange(int i, int j) {
        return i ? this->nums[j] - this->nums[i - 1] : this->nums[j];
    }
private:
    vector<int> nums;
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray obj = new NumArray(nums);
 * int param_1 = obj.sumRange(i,j);
 */

int main(){
    Solution s;

    return 0;
}