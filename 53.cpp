//
//@author Xiao Xu
//@create 2018-08-09 21:34
// Maximum Subarray
//使用动态规划，下一步学习如何使用分治
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if(nums.size() == 0){
            return 0;
        }
        int last, max_length;
        last = nums[0];
        max_length = last;
        for(int i = 1; i < nums.size();i++){
            last = last > 0 ? nums[i] + last : nums[i];
            max_length = max(max_length, last);
        }
        return max_length;
    }
};

int main(){
    //Solution s;
    return 0;
}

