//
//@author Xiao Xu
//@create 2018-09-04 22:27
//Combinations
//
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> result;
        if(n < k || n < 0 || k < 0)
            return result;

        vector<int> nums(k, 0);
        getCombine(result, n, k, 0, nums);

        return result;
    }

    void getCombine(vector<vector<int>>& result, int n, int k, int begin, vector<int>& nums){
        if(!k){
            result.push_back(nums);
            return ;
        }

        if(begin + k > n)
            return ;
        for(int i = begin; i < n - k + 1; i++){
            vector<int> new_nums = nums;
            new_nums[new_nums.size() - k] = i + 1;
            getCombine(result, n, k - 1, i + 1, new_nums);
        }
    }
};

int main() {
    Solution s;

    return 0;
}
