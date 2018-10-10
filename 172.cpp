//
//@author Xiao Xu
//@create 2018-10-09 22:33
//Factorial Trailing Zeroes
//有多少10取决于有多少个2与5，更进一步，取决于有多少个5
//虽然发现做法，但时间复杂度仍不合格，最后参考评论区

#include <iostream>
using namespace std;

class Solution {
public:
    int trailingZeroes(int n) {
        int result = 0;
        for(long long i=5; n/i>0; i*=5){
            result += (n/i);
        }
        return result;
    }
};

int main() {
    Solution s;

    return 0;
}
