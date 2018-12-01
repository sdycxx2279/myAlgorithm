//
//@author Xiao Xu
//@create 2018-12-01 11:59
//Power of Four
//确保num大于零，形式为1000..且0有偶数个
//

#include <iostream>
using namespace std;

class Solution {
public:
    bool isPowerOfFour(int num) {
        return num > 0 && (num & (num - 1)) == 0 && (num - 1) % 3 == 0;
    }
};

int main() {
    Solution s;

    return 0;
}
