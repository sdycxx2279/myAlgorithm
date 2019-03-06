//
//@author Xiao Xu
//@create 2019-03-04 21:10
//Matchsticks to Square
//dfs加各种剪枝
//

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    bool makesquare(vector<int>& nums) {
        if(nums.size() < 4)
            return false;
        vector<int> side(4, 0);
        int sum = 0;
        for(int num : nums){
            sum += num;
        }
        //剪枝1
        if(sum % 4 != 0 || sum == 0)
            return false;
        //剪枝2，优化最大
        sort(nums.begin(), nums.end(), [](const int &l, const int &r){return l > r;});
        return dfs(side, nums, 0, sum / 4);
    }

    bool dfs(vector<int>& side, vector<int>& nums, int index, int side_length){
        if(index == nums.size())
            return side[0] == side[1] && side[1] == side[2] && side[2] == side[3];

        for(int i = 0; i < 4; i++){
            //剪枝3
            int j = i - 1;
            while(j >= 0){
                if(side[j] == side[i])
                    break;
                j--;
            }
            if(j != -1)
                continue;
            side[i] += nums[index];
            if(side[i] <= side_length && dfs(side, nums, index + 1, side_length))
                return true;
            side[i] -= nums[index];
        }

        return false;
    }
};

int main(){
    Solution s;

    return 0;
}