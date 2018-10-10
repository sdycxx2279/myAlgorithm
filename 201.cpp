//
//@author Xiao Xu
//@create 2018-10-10 21:37
//Bitwise AND of Numbers Range
//学习讨论区， 当m~n至少包含两位数时，他们二进制最后一位必包含0与1，即必为0，可接着比较上一位
//

#include <iostream>
using namespace std;

class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        return m < n ? rangeBitwiseAnd(m / 2, n / 2) << 1 : m;
    }
};

int main() {
    Solution s;

    return 0;
}
