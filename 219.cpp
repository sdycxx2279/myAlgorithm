//
//@author Xiao Xu
//@create 2018-10-19 15:28
//Contains Duplicate II
//
//

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, int> m;
        for(int i = 0; i <nums.size(); i++){
            if(m[nums[i]] && i - m[nums[i]] + 1 <= k){
                return true;
            }

            m[nums[i]] = i + 1;
        }
        return false;
    }
};

int main() {
    Solution s;

    return 0;
}
