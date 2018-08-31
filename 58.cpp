//
//@author Xiao Xu
//@create 2018-08-30 22:21
//Length of Last Word
//
//

#include <iostream>
using namespace std;

class Solution {
public:
    int lengthOfLastWord(string s) {
        int m = s.size() - 1;
        while(m >= 0 && s[m] == ' ')
            m--;
        if(m < 0)
            return 0;
        return m - s.substr(0, m).find_last_of(" ");
    }
};

int main() {
    Solution s;

    return 0;
}
