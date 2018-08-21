//
//@author Xiao Xu
//@create 2018-08-21 22:34
//Permutations II
//for循环中使用continue跳过不需要的迭代
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> result;
        sort(nums.begin(), nums.end());

        getPermute(result, nums, 0);
        return result;
    }

    void getPermute( vector<vector<int>>& result, vector<int> nums, int begin){
        if(begin == nums.size())
            result.push_back(nums);
        else{
            for(int i = begin; i < nums.size(); i++){
                if(i != begin && nums[i] == nums[begin])
                    continue;
                swap(nums[i], nums[begin]);

                getPermute(result, nums, begin + 1);
            }
        }
    }
};

int main() {
    Solution s;
    vector<int> nums = {1,2,1};
    vector<vector<int>> result = s.permuteUnique(nums);
    return 0;
}
