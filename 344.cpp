//
//@author Xiao Xu
//@create 2018-12-01 12:00
//Reverse String
//
//

#include <iostream>
using namespace std;

class Solution {
public:
    string reverseString(string s) {
        int left = 0, right = s.size() - 1;
        while(left < right){
            swap(s[left++], s[right--]);
        }
        return s;
    }
};

int main() {
    Solution s;

    return 0;
}
