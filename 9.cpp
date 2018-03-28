//
//@author Xiao Xu
//@create 2018-03-28 10:02
//
#include<iostream>
#include <cmath>

using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0)
            return false;
        else if(x < 10)
            return true;
        int reverse = 0;
        int num = x;
        while(x >= 1){
            if(reverse > (INT64_MAX - x % 10) / 10){
                return false;
            }
            reverse = reverse * 10 + x % 10;
            x = x / 10;
        }
        return (reverse == num) || (reverse == num * 10);
    }
};

int main(){
    Solution s;
    cout<<s.isPalindrome(121);
    return 0;
}
