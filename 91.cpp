//
//@author Xiao Xu
//@create 2018-08-16 22:53
//Decode Ways
//忘记当数字小于10时不能识别为两位数
//

#include <iostream>
using namespace std;

class Solution {
public:
    int numDecodings(string s) {
        if(s.size() == 0 || s[0] == '0')
            return 0;
        int a, b;
        a = 1;
        b = 1;
        for(int i = 1; i < s.size(); i++){
            if(isZero(s[i]) && lessThan26(s[i-1], s[i])){
                b = a;
            }else if(isZero(s[i]) && !lessThan26(s[i-1], s[i])){
                return 0;
            }else if(!isZero(s[i]) && lessThan26(s[i-1], s[i])){
                int temp = b + a;
                a = b;
                b = temp;
            }else{
                a = b;
            }
        }
        return b;
    }

    bool isZero(char c){
        return c == '0';
    }

    bool lessThan26(char a, char b){
        int result = (a - '0') * 10 + (b - '0');
        return (result  <= 26) && (result >= 10);
    }
};

int main() {
    Solution s;
    cout<<s.numDecodings("24726");
    return 0;
}
