//
//@author Xiao Xu
//@create 2018-09-04 22:27
//Subsets
//
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result;
        for(int i = 0; i<= nums.size(); i++){
            vector<int> subset(i, 0);
            getCombine(result, nums.size(), i, 0, nums, subset);
        }
        return result;
    }
    void getCombine(vector<vector<int>>& result, int n, int k, int begin, vector<int>& nums, vector<int> subset){
        if(!k){
            result.push_back(subset);
            return ;
        }

        if(begin + k > n)
            return ;
        for(int i = begin; i < n - k + 1; i++){
            vector<int> new_nums = subset;
            new_nums[new_nums.size() - k] = nums[i];
            getCombine(result, n, k - 1, i + 1, new_nums, new_nums);
        }
    }
};

int main() {
    Solution s;

    return 0;
}
