//
//@author Xiao Xu
//@create 2019-01-04 23:02
//Convert a Number to Hexadecimal
//学习自讨论区
//忘记0，WA一次

#include <iostream>
using namespace std;

class Solution {
public:
    string toHex(int num) {
        if(!num)
            return "0";
        string m = "0123456789abcdef", res = "";
        int count = 8;

        while(num && count){
            count--;
            res = m[num & 15] + res;
            num >>= 4;
        }

        return res;
    }
};

int main() {
    Solution s;

    return 0;
}
