//
//@author Xiao Xu
//@create 2018-10-09 22:20
//Excel Sheet Column Title
//一开始以为最多只有两位，ZZ之后就没有了，其实ZZ后是AAA，以此类推
//

#include <iostream>
using namespace std;

class Solution {
public:
    string convertToTitle(int n) {
        string result = "";
        while(n > 0){
            int num = n % 26;
            n = n / 26;
            if(num == 0){
                num = 26;
                n--;
            }
            char c = ('A' + (num - 1));
            result  =  c + result;
        }

        return result;
    }
};

int main() {
    Solution s;

    return 0;
}
