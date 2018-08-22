//
//@author Xiao Xu
//@create 2018-08-20 21:35
//
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

    void getPermute( vector<vector<int>>& result, vector<int>& nums, int begin){
        if(begin == nums.size())
            result.push_back(nums);
        else{
            for(int i = 0; i < nums.size(); i++){
                vector<int> new_nums = nums;
                swap(new_nums[i], new_nums[begin]);

                getPermute(result, new_nums, begin + 1);
                while(i < nums.size() && nums[i] == nums[i+1]){
                    i++;
                }
            }
        }
    }
};

int main(){
    Solution s;
    cout<<;
    return 0;
}

