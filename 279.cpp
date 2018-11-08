//
//@author Xiao Xu
//@create 2018-11-08 22:35
//Perfect Squares
//学习自讨论区，dp算法
//最快算法，基于四平方定理：任何一个正整数都可以表示成不超过四个整数的平方之和
//广度优先搜索，将n个数字视为点，若两点可通过加减一个完美平方数得到则有边

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int numSquares(int n) {
        if(n <= 0)
            return 0;
        vector<int> nums;
        nums.push_back(0);
        while(nums.size() <= n){
            int m = nums.size();
            int num = INT_MAX;
            for(int i = 1; i * i <= m; i++){
                num = min(num, nums[m - i * i] + 1);
            }
            nums.push_back(num);
        }

        return nums[n];
    }
};

int main() {
    Solution s;

    return 0;
}
