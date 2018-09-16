//
//@author Xiao Xu
//@create 2018-09-14 15:33
//Single Number
//
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int num = nums[0];
        for(int i = 1; i < nums.size(); i++){
            num = num ^nums[i];
        }
        return num;
    }
};

int main() {
    Solution s;

    return 0;
}
