//
//@author Xiao Xu
//@create 2018-09-13 22:34
//Subsets II
//
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> result;
        if(nums.empty())
            return result;
        vector<int> temp;
        result.push_back(temp);
        sort(nums.begin(), nums.end());

        int result_size = 0;
        for(int i = 0; i < nums.size(); i++){
            int start_index = i > 0 && nums[i] == nums[i-1] ? result_size : 0;
            result_size = result.size();
            for(int j = start_index; j < result_size; j++){
                temp = result[j];
                temp.push_back(nums[i]);
                result.push_back(temp);
            }
        }

        return result;
    }
};

int main() {
    Solution s;

    return 0;
}
