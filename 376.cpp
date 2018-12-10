//
//@author Xiao Xu
//@create 2018-12-10 21:10
//Wiggle Subsequence
//dp
//

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        if(nums.size() == 2 && nums[0] == nums[1])
            return 1;
        if(nums.size() <= 2)
            return nums.size();
        vector<int> wiggle(nums.size() - 1, 0);
        vector<int> pos(nums.size() - 1, 1);
        vector<int> neg(nums.size() - 1, 1);

        for(int i = 0; i < nums.size() - 1; i++){
            wiggle[i] = nums[i + 1] - nums[i];
        }

        int last_neg = -1, last_pos = -1;
        for(int i = 0; i < wiggle.size(); i++){
            if(wiggle[i] == 0)
                continue;
            else if(wiggle[i] < 0){
                last_neg = i;
                if(last_pos != -1)
                    neg[i] = pos[last_pos] + 1;
            }else{
                last_pos = i;
                if(last_neg != -1)
                    pos[i] = neg[last_neg] + 1;
            }
        }
        if(last_pos == -1 && last_neg == -1)
            return 1;
        else if(last_pos == -1 || last_neg == -1)
            return 2;

        return max(pos[last_pos], neg[last_neg]) + 1;
    }

//    if (nums.empty())
//    return 0;
//    int inc = 1, dec = 1;
//    for (int i = 1; i < nums.size(); i++) {
//        if (nums[i] > nums[i-1])
//            inc = dec+1;
//        else if (nums[i] < nums[i-1])
//            dec = inc+1;
//    }
//    return max(inc, dec);
};

int main(){
    Solution s;

    return 0;
}