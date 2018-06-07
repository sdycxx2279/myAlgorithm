//
//@author Xiao Xu
//@create 2018-06-06 21:07
// Search Insert Position
//
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int start, end, mid;
        start = 0;
        end = nums.size() - 1;
        mid = - 1;
        while(start <= end){
            mid = (start + end) / 2;
            if(nums[mid] == target){
                return mid;
            }else if(nums[mid] < target){
                start = mid + 1;
            }else{
                end = mid - 1;
            }
        }
        if(mid == -1)
            return 0;
        else{
            return nums[mid] < target ? mid+1:mid;
        }
    }
};

int main() {
    Solution s;
    vector<int> v = {1, 3, 5, 6};
    cout<<s.searchInsert(v, 5);
    return 0;
}

//    int low = 0, high = nums.size()-1;
//
//    // Invariant: the desired index is between [low, high+1]
//    while (low <= high) {
//        int mid = low + (high-low)/2;
//
//        if (nums[mid] < target)
//            low = mid+1;
//        else
//            high = mid-1;
//    }
//
//    // (1) At this point, low > high. That is, low >= high+1
//    // (2) From the invariant, we know that the index is between [low, high+1], so low <= high+1. Follwing from (1), now we know low == high+1.
//    // (3) Following from (2), the index is between [low, high+1] = [low, low], which means that low is the desired index
//    //     Therefore, we return low as the answer. You can also return high+1 as the result, since low == high+1
//    return low;