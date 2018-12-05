//
//@author Xiao Xu
//@create 2018-12-05 21:10
//Count Numbers with Unique Digits
//

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        if(!n)
            return 1;
        int a = 1, b = 10, c = 9;
        for(int i = 1; i < n; i++){
            int temp = b;
            b = (b - a) * c + b;
            c--;
            a = temp;
        }
        return b;
    }
};

int main(){
    Solution s;

    return 0;
}