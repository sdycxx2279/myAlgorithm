//
//@author Xiao Xu
//@create 2018-10-09 22:32
//Excel Sheet Column Number
//
//

#include <iostream>
using namespace std;

class Solution {
public:
    int titleToNumber(string s) {
        int result = 0;
        for(int i = 0; i < s.size(); i++){
            result = result * 26 + (s[i] - 'A' + 1);
        }

        return result;
    }
};

int main() {
    Solution s;

    return 0;
}
