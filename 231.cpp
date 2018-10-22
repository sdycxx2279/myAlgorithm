//
//@author Xiao Xu
//@create 2018-10-22 21:19
//Power of Two
//2的次幂2进制数必为1加n个0，其减1比为n个1，&后为0

#include<iostream>
using namespace std;

class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n == 1)
            return true;
        while(n % 2 == 0 && n != 0){
            n = n / 2;
            if(n == 1)
                return true;
        }
        return false;
    }

    //return (n > 0) && (n & (n-1)) == 0;
};

int main(){
    Solution s;

    return 0;
}





