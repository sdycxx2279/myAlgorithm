//
//@author Xiao Xu
//@create 2018-08-16 22:53
//Climbing Stairs
//动态规划，没啥难度
//

#include <iostream>
using namespace std;

class Solution {
public:
    int climbStairs(int n) {
        int a = 1;
        int b = 2;

        for(int i = 2; i < n; i++){
            int temp = a + b;
            a = b;
            b = temp;
        }
        return n <= 1 ? a : b;
    }
};

int main() {
    Solution s;
    cout<<s.climbStairs(2);
    return 0;
}
