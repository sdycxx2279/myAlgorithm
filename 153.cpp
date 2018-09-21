//
//@author Xiao Xu
//@create 2018-09-21 20:25
//Find Minimum in Rotated Sorted Array
//
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int findMin(vector<int>& nums) {
        if(nums.empty())
            return 0;
        if(nums.size() == 1)
            return nums[0];

        int left = 0, right = nums.size() - 1;
        while(left < right){
            if(left + 1 == right)
                return nums[left] > nums[right] ? nums[right] : nums[left];
            int mid = (left + right) / 2;
            if(nums[mid] > nums[left] && nums[mid] < nums[right])
                return  nums[left];
            else if(nums[mid] < nums[left])
                right = mid;
            else
                left = mid;
        }
    }
};

int main() {
    Solution s;

    return 0;
}
