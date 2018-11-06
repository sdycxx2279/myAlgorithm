//
//@author Xiao Xu
//@create 2018-11-06 21:10
//Add Digits
//最笨的做法得到结果
//N=(a[0] * 1 + a[1] * 10 + ...a[n] * 10 ^n)，  M = a[0] + a[1] + ..a[n]， N % 9 = M

#include<iostream>
using namespace std;

class Solution {
public:
    int addDigits(int num) {
        int result;
        while(true){
            result = 0;
            while(num != 0){
                result += num % 10;
                num /= 10;
            }
            if(result < 10)
                return result;
            num = result;
        }

    }

    //return (num - 1) % 9 + 1;
};

int main(){
    Solution s;

    return 0;
}