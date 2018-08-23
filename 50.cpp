//
//@author Xiao Xu
//@create 2018-08-23 22:39
//Pow(x, n)
//使用二分法，但本题按照设定数值不会超出范围吗？
//忘记处理n = 0情况
//

#include <iostream>
using namespace std;

class Solution {
public:
    double myPow(double x, int n) {
        if(x == 0)
            return 0;
        else if(n == -1)
            return 1 / x;
        else if(n == 1)
            return x;
        else if(n == 0)
            return 1;
        else if(n % 2 == 0)
            return myPow(x * x, n / 2);
        else
            return x * myPow(x, n - 1);
    }
};

int main() {
    Solution s;

    return 0;
}
