//
//@author Xiao Xu
//@create 2018-08-08 14:06
// House Robber
//
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size() == 0)
            return 0;
        vector<int> rob_num;
        for(int i = 0 ; i < nums.size(); i++){
            if(i > 2)
                rob_num.push_back( max(rob_num[i - 2] + nums[i], rob_num[i - 3] + nums[i - 1]));
            else if(i == 2)
                rob_num.push_back(max(nums[0] + nums[2], nums[1]));
            else if(i == 1)
                rob_num.push_back(max(nums[0], nums[1]));
            else
                rob_num.push_back(nums[0]);
        }
        return rob_num[nums.size() - 1];
    }
};

int main(){
    return 0;
}