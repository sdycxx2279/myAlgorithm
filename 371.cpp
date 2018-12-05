//
//@author Xiao Xu
//@create 2018-12-05 21:10
//Sum of Two Integers
//学习自讨论区，位运算，没看懂。。。。
//

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int getSum(int a, int b) {
        return b==0? a:getSum(a^b, (a&b)<<1);
    }
};

int main(){
    Solution s;

    return 0;
}