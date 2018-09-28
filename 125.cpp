//
//@author Xiao Xu
//@create 2018-09-28 21:55
//Valid Palindrome
//isLetter分为识别与大小写转换两个函数速度更快，但懒得改了。。
//

#include <iostream>
using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        int left = 0, right = s.size() - 1;

        while(left < right){
            while(isLetter(s[left]) == ' ' && left < right)
                left++;
            while(isLetter(s[right]) == ' ' && left < right)
                right--;
            if(isLetter(s[left]) != isLetter(s[right]))
                return false;
            left++;
            right--;
        }

        return true;
    }

    char isLetter(char c){
        if((c >= 'a' && c <= 'z') ||(c >= '0' && c <= '9'))
            return c;
        else if(c >= 'A' && c <= 'Z')
            return c + 32;
        else
            return ' ';
    }
};

int main() {
    Solution s;

    return 0;
}
