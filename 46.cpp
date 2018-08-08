//
//@author Xiao Xu
//@create 2018-08-08 12:06
// Permutations
//传入vector参数时，使用&传入实参，否则传入形参
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> result;
        get_permute(nums, 0, result);
        return result;
    }

    void get_permute(vector<int>& nums, int n_begin, vector<vector<int>>& result){
        if(n_begin == nums.size() - 1){
            result.push_back(nums);
        } else{
            for(int i = n_begin; i < nums.size(); i++){
                vector<int> new_nums;
                new_nums.assign(nums.begin(), nums.end());
                swap(new_nums[i], new_nums[n_begin]);
                get_permute(new_nums, n_begin + 1, result);
            }
        }

    }
};

int main(){
    return 0;
}
