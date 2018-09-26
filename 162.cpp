//
//@author Xiao Xu
//@create 2018-09-26 20:27
//Find Peak Element
//
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int left = 0, right = nums.size() - 1;
        while(left <= right) {
            int mid = (left + right) / 2;
            if (mid == 0 && nums[0] < nums[1])
                return nums[1];
            else if ((mid == 0 && nums[0] > nums[1]) || (mid == nums.size() - 1) ||
                     (nums[mid] > nums[mid - 1] && nums[mid] > nums[mid + 1]))
                return nums[mid];
            else if (nums[mid] < nums[mid - 1] && nums[mid] > nums[mid + 1])
                right = mid - 1;
            else
                left = mid + 1;
        }
        return 0;
    }
};

int main() {
    Solution s;

    return 0;
}


//int findPeakElement(vector<int>& num) {
//    if (num.size() <= 1) return 0;
//    int mid = 0, l = 0, h = num.size() - 1;
//
//    while (l < h) {
//        mid = (l + h) / 2;
//        if (num[mid] > num[mid + 1])
//            h = mid;
//        else
//            l = mid + 1;
//    }
//
//    return l;
//}

