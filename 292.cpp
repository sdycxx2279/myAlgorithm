//
//@author Xiao Xu
//@create 2018-11-18 14:03
//Nim Game
//脑筋急转弯
//

#include <iostream>
using namespace std;

class Solution {
public:
    bool canWinNim(int n) {
        return static_cast<bool>(n % 4);
    }
};

int main() {
    Solution s;

    return 0;
}
