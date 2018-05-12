//
//@author Xiao Xu
//@create 2018-05-11 10:41
//4Sum
//第一与第二个值不一定小于target，受15题sum=0影响思考失误
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> result;
        int length_nums = nums.size();
        int left,right;
        sort(nums.begin(),nums.end());
        for(int i = 0; i < length_nums; i++){
            if(i > 0 && nums[i] == nums[i-1])
                continue;


            // 最优代码剪枝操作
            // 此处剪枝格外重要，未剪枝60ms，剪枝15ms
//                if (nums[a] + nums[sz - 3] + nums[sz - 2] + nums[sz - 1] < target) {
//                    continue;
//                }
//                if (nums[a] + nums[a + 1] + nums[a + 2] + nums[a + 3] > target) {
//                    return ret;
//                }

            for(int j = i + 1; j < length_nums; j++){
                if(j > i + 1 && nums[j] == nums[j-1])
                    continue;

                // 此处剪枝可从15ms到12ms，要注意若>target, 不能直接return了，只是内层b循环不必再试，外层a循环还要继续
//                if (nums[a] + nums[b] + nums[sz - 2] + nums[sz - 1] < target) {
//                    continue;
//                }
//                if (nums[a] + nums[b] + nums[b + 1] + nums[b + 2] > target) {
//                    break;
//                }

                left = j + 1;
                right = length_nums - 1;
                while(left < right){
                    int temp = nums[i] + nums[j] + nums[left] + nums[right];
                    if(temp == target){
                        result.push_back({nums[i],nums[j],nums[left],nums[right]});
                        left++;
                        right--;
                        while(left < right && nums[left - 1] == nums[left]){
                            left++;
                        }
                        while(left < right && nums[right + 1] == nums[right]){
                            right--;
                        }
                    }else if(temp < target){
                        left++;
                    }else{
                        right--;
                    }
                }
            }
        }
        return result;
    }
};

int main() {
    Solution s;
    vector<int> v = {1,0,-1,0,-2,2};
    s.fourSum(v,0);
    return 0;
}
