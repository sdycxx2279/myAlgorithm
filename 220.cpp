//
//@author Xiao Xu
//@create 2018-10-19 15:29
//Contains Duplicate III
//学习自讨论区，使用set的lower_bound函数
//

#include <iostream>
#include <vector>
#include <set>

using namespace std;

class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        if(t < 0)
            return false;
        set<int> k_nums;
        for(int i = 0; i < nums.size(); i++){
            if(k_nums.size() > k)
                k_nums.erase(nums[i - k - 1]);

            int min_num = nums[i] < INT_MIN + t ? INT_MIN : nums[i] - t;
            set<int>::iterator pos = k_nums.lower_bound(min_num);
            int max_num = nums[i] > INT_MAX - t ? INT_MAX : nums[i] + t;
            if(pos != k_nums.end() && *pos <= max_num)
                return true;
            k_nums.insert(nums[i]);
        }
        return false;
    }
};

int main() {
    Solution s;

    return 0;
}
