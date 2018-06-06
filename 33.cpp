//
//@author Xiao Xu
//@create 2018-06-01 10:57
//Search in Rotated Sorted Array
//二分查找，将数组一分为二，必有一为顺序，判断target是否在顺序数组中，不在继续查找另一半数组
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int nums_length = nums.size();
        if(nums_length == 0)
            return -1;
        int i, j, mid;
        i = 0;
        j = nums_length - 1;
        while(i <= j){
            mid = (i+j)/2;
            if(nums[mid] == target){
                return mid;
            }
            if(nums[i] <= nums[mid]){
                if(nums[i] <= target && nums[mid] > target){
                    j = mid - 1;
                }else{
                    i = mid + 1;
                }
            } else{
                if(nums[mid] < target && nums[j] >= target){
                    i = mid + 1;
                }else{
                    j = mid - 1;
                }
            }
        }
        return -1;
    }
};

int main() {
    Solution s;
    vector<int> nums = {4,5,6,7,0,1,2};
    cout<<s.search(nums,0);
    return 0;
}
