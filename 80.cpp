//
//@author Xiao Xu
//@create 2018-09-06 22:34
//Remove Duplicates from Sorted Array II
//
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(!nums.size())
            return 0;
        int pointer = 0;
        bool duplicate = true;
        for(int i = 1; i < nums.size(); i++){
            if(nums[i] == nums[pointer] && duplicate){
                duplicate = false;
                nums[++pointer] = nums[i];
            }else if(nums[i] != nums[pointer]){
                duplicate = true;
                nums[++pointer] = nums[i];
            }
        }
        return pointer + 1;
    }
};

int main() {
    Solution s;

    return 0;
}
