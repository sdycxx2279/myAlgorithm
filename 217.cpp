//
//@author Xiao Xu
//@create 2018-10-16 23:16
// Contains Duplicate
//

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        for(int i = 1; i < nums.size(); i++){
            if(nums[i] == nums[i - 1])
                return true;
        }
        return false;
    }
};

int main(){
    Solution s;

    return 0;
}





