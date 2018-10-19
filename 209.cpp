//
//@author Xiao Xu
//@create 2018-10-11 22:21
//Minimum Size Subarray Sum
//O(N)复杂度，因为内部的while循环最多只会执行n次，（每次left++，最多加到n）
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int left = 0, sum = 0, result = nums.size() + 1;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] >= s)
                return 1;
            sum += nums[i];
            if(sum >= s){
                while(left < i && sum >= s){
                    result = min(result, i - left + 1);
                    sum -= nums[left];
                    left++;
                }
            }
        }
        return result > nums.size() ? 0 : result;
    }
};

int main() {
    Solution s;

    return 0;
}
