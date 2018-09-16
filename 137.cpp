//
//@author Xiao Xu
//@create 2018-09-14 15:33
//Single Number II
//参考http://liadbiz.github.io/leetcode-single-number-problems-summary/
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int x1 = 0, x2 = 0, mask = 0;
        for (int num : nums) {
            x2 ^= (x1 & num);
            x1 ^= num;
            mask = ~(x1 & x2);
            x2 = mask & x2;
            x1 = mask & x1;
        }

        return x1;
    }
};

int main() {
    Solution s;

    return 0;
}
