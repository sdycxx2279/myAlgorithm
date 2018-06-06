//
//@author Xiao Xu
//@create 2018-06-06 21:06
//Search for a Range
//
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> result;
        int start = 0;
        int end = nums.size() - 1;
        int mid;
        while(start <= end){
            mid = (start + end) / 2;
            if(nums[mid] == target){
                break;
            }else if(nums[mid] < target){
                start = mid + 1;
            }else{
                end = mid - 1;
            }
        }
        if(nums.size() != 0 && nums[mid] == target){
            start = end = mid;
            while(start > 0 && nums[start-1] == target){
                start--;
            }
            while(end < nums.size() - 1 && nums[end+1] == target){
                end++;
            }
            result.push_back(start);
            result.push_back(end);
        }else{
            result.push_back(-1);
            result.push_back(-1);
        }
        return result;
    }
};

int main() {
    Solution s;

    return 0;
}
