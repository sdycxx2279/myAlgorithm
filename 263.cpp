//
//@author Xiao Xu
//@create 2018-11-07 21:10
//Ugly Number
//

#include<iostream>
using namespace std;

class Solution {
public:
    bool isUgly(int num) {
        if(num <= 0)
            return false;
        if(num == 1)
            return true;
        while(!(num % 2) || !(num % 3) || !(num % 5)){
            if(!(num % 2)){
                num /= 2;
            }else if(!(num % 3))
                num /= 3;
            else
                num /= 5;
            if(num == 1)
                return true;
        }
        return false;
    }
};

int main(){
    Solution s;

    return 0;
}