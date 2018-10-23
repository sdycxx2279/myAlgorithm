//
//@author Xiao Xu
//@create 2018-10-23 20:58
//Product of Array Except Self
//学习自讨论区，第一遍便利将对应位置赋值为该位置左侧所有值乘积，第二次从右边遍历，再乘以其右侧所有数值乘积

#include<iostream>
using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> result(nums.size(), 1);

        int p = 1;
        for(int i = 0; i < nums.size(); i++){
            result[i] = p;
            p *= nums[i];
        }

        p = 1;
        for(int i = nums.size() - 1; i >= 0; i--){
            result[i] *= p;
            p *= nums[i];
        }

        return result;
    }


};

int main(){
    Solution s;

    return 0;
}



