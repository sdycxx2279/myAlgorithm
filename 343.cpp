//
//@author Xiao Xu
//@create 2018-12-01 11:59
//Integer Break
//动态规划
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int integerBreak(int n) {
        vector<int> nums(n, 1);
        for(int i = 2; i < n; i++){
            int temp = 0;
            for(int j = 0; j < i; j++){
                temp = max(temp, max(j+1, nums[j]) * (i - j));
            }
            //cout<<temp<<endl;
            nums[i] = temp;
        }
        return nums[n - 1];
    }
};

int main() {
    Solution s;

    return 0;
}
