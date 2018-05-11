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
            for(int j = i + 1; j < length_nums; j++){
                if(j > i + 1 && nums[j] == nums[j-1])
                    continue;
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
