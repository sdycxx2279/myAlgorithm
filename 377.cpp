//
//@author Xiao Xu
//@create 2018-12-10 21:10
//Combination Sum IV
//dp
//

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        if(nums.empty() || target <= 0)
            return 0;
        vector<int> res(target + 1, 0);
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] <= target)
                res[nums[i]]++;
        }

        for(int i = 1; i <= target; i++){
            if(!res[i])
                continue;
            for(int j = 0; j < nums.size(); j++){
                if(i + nums[j] <= target)
                    res[i + nums[j]] += res[i];
            }
        }

        return res[target];
    }

    //精简代码
//    int combinationSum4(vector<int>& nums, int target) {
//        vector<int> result(target + 1);
//        result[0] = 1;
//        for (int current = 1; current <= target; current++) {
//            for (int value : nums) {
//                if (current - value >= 0) {
//                    result[current] += result[current - value];
//                }
//            }
//        }
//
//        return result[target];
//    }
};

int main(){
    Solution s;

    return 0;
}