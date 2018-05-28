//
//@author Xiao Xu
//@create 2018-05-23 11:05
//Divide Two Integers
//使用移位运算符进行二分查找
//

#include <iostream>
#include <cstdlib>

using namespace std;

class Solution {
public:
    int divide(int dividend, int divisor) {
        if(dividend == 0)
            return 0;
        if(dividend == INT32_MIN & divisor == -1){
            return  INT_MAX;
        }
        if(divisor == 1){
            return dividend;
        }else if(divisor == -1){
            return -dividend;
        }
        bool flag = (dividend < 0) ^ (divisor < 0);
        long long dividend_pos = labs(dividend);
        long long divisor_pos = labs(divisor);
        int result = divide_Pos(dividend_pos, divisor_pos);
        return flag  ? -result: result;

    }
    long long divide_Pos(long long dividend, long long divisor){
        if(dividend < divisor)
            return 0;
        else if(dividend < (divisor << 1))
            return 1;
        else{
            long long times = 1;
            long long temp_divisor = divisor;
            while(dividend >= (temp_divisor << 1)){
                temp_divisor <<= 1;
                times <<= 1;
            }
            return times + divide_Pos(dividend - temp_divisor, divisor);
        }
    }
};

int main() {
    Solution s;
    cout<<s.divide(2147483647,2)<<endl;
    return 0;
}
