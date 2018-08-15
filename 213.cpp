//@author Xiao Xu
//@create 2018-08-09 21:35
//House Robber II
//将问题分解为两个问题198，并优化了空间复杂度
//非循环变量最好不要命名为i，容易搞混。。。囧

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size() - 1;
        if(n < 1){
            return n ? 0 : nums[0];
        }
        return max(get_rob(nums, 0, n-1), get_rob(nums, 1, n));
    }
    int get_rob(vector<int>& nums, int begin, int end){
        int i = 0;
        int e = 0;
        for(int j = begin; j <= end; j++){
            int temp = max(i, e);
            i = e + nums[j];
            e = temp;
        }
        return max(i, e);
    }
};

int main(){
    Solution s;
    return 0;
}

