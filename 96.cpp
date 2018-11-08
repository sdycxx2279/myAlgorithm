//
//@author Xiao Xu
//@create 2018-09-16 11:29
//Unique Binary Search Trees
//dp算法，学习自讨论区，F(i, n) = G(i-1) * G(n-i)， G(n) = F(1, n) + F(2, n) + ... + F(n, n).
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int numTrees(int n) {
        vector<int> nums(n + 1,0);
        nums[0] = 1;
        nums[1] = 1;
        for(int i = 2; i <= n; i++){
            for(int j = 1; j <= i; j++){
                nums[i] += nums[j - 1] * nums[i - j];
            }
        }
        return nums[n];
    }
};

int main() {
    Solution s;

    return 0;
}
