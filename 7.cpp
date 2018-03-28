//
//@author Xiao Xu
//@create 2018-03-27 12:33
//
#include<iostream>
#include<cmath>

using namespace std;

class Solution {
public:
    int reverse(int x) {
        int answer = 0;
        bool negative = x<0;
        x = abs(x);
        while(x >= 1){
            if(answer > (INT32_MAX - x % 10) / 10){
                return 0;
            }
            answer = answer * 10 + x % 10;
            x = x / 10;
        }
        return negative ? -answer : answer;
    }
};
int main(){
    Solution s;
    cout<<s.reverse(-120);
    return 0;
}

