//
//@author Xiao Xu
//@create 2018-08-31 12:25
//Add Binary
//使用指针与字符累加而不是substr更快
//

#include <iostream>
using namespace std;

class Solution {
public:
    string addBinary(string a, string b) {
        int carry = 0;
        int len_a = a.size() - 1, len_b = b.size() - 1;
        string s = len_a > len_b ? a : b;
        int len_s = s.size();


        while(len_a >= 0 && len_b >= 0){
            int result = carry + (a[len_a--] - '0') + (b[len_b--] - '0');
            carry = result / 2;
            s[len_s--] = '0' + result % 2;
        }
        while(len_a >= 0 && carry){
            int result = carry + (a[len_a--] - '0');
            carry = result / 2;
            s[len_s--] = '0' + result % 2;
        }
        while(len_b >= 0 && carry){
            int result = carry + (b[len_b--] - '0');
            carry = result / 2;
            s[len_s--] = '0' + result % 2;
        }

        //节省代码
//        while(la>0 || lb>0 || c){
//            c += la>0 ? a[la-1] - '0' : 0;
//            c += lb>0 ? b[lb-1] - '0' : 0;
//            res = char('0' + c%2) + res;
//            c /= 2;
//            la--;
//            lb--;
//        }

        if(carry)
            s.insert(s.begin(), '1');
        return s;
    }
};

int main() {
    Solution s;

    return 0;
}
