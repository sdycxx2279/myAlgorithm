//
//@author Xiao Xu
//@create 2018-12-26 21:10
//Nth Digit
//学习自讨论区，分三步走：1、确定答案所在数位数，2、确定答案所在数，3、确定答案
//

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int findNthDigit(int n) {
        int digits = 1, base = 9;
        while(INT_MAX / digits > base && n - digits * base > 0){
            n -= digits * base;
            digits++;
            base *= 10;
            //cout<<n<<endl;
        }

        int res = pow(10, digits - 1);
        res += (n / digits - 1);

        int num = n % digits;
        if(num){
            res++;
            num = digits - num;
            while(num){
                num--;
                res = res / 10;
            }
        }
        return res % 10;

    }
};

int main(){
    Solution s;

    return 0;
}