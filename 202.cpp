//
//@author Xiao Xu
//@create 2018-10-10 21:37
//Happy Number
//
//

#include <iostream>
#include <unordered_map>
using namespace std;

class Solution {
public:
    bool isHappy(int n) {
        unordered_map<int, int> m;
        while(!m[n]++) {
            int temp = 0;

            while (n != 0) {
                int num = n % 10;
                temp += num * num;
                n = n / 10;
            }

            n = temp;
            if (n == 1)
                return true;
        }

        return false;
    }
};

int main() {
    Solution s;

    return 0;
}
