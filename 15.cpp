//
//@author Xiao Xu
//@create 2018-05-07 10:36
//3Sum
//set设置的位置问题
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        sort(nums.begin(),nums.end());
        for(int i = 0; i < nums.size(); i++){
            if(i > 0 && nums[i] == nums[i-1])
                continue;
            set<int> numSet;
            for(int j = i + 1; j < nums.size(); j++){
                if(numSet.count(-(nums[i] + nums[j]))){
                    result.push_back({-nums[i] - nums[j], nums[i], nums[j]});
                }
                bool first = true;
                while(j + 1 < nums.size() && nums[j] == nums[j+1]){
                    if(first && nums[i] + nums[j] * 2 == 0){
                        first = false;
                        result.push_back({nums[i], nums[j], nums[j]});
                    }
                    j++;
                }
                numSet.insert(nums[j]);
            }
        }
        return result;
    }
};

int main() {
    Solution s;
    vector<int> v = {0,0,0};
    vector<vector<int>> result = s.threeSum(v);
    return 0;
}
