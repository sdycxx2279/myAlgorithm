//
//@author Xiao Xu
//@create 2018-08-30 22:22
//Plus One
//
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        bool carry = true;
        int m = digits.size();

        if(!m)
            return digits;

        for(int i = m - 1; i >= 0 && carry; i--){
            if(digits[i] == 9)
                digits[i] = 0;
            else{
                digits[i]++;
                carry = false;
            }

            //优化版本
            //int newval = digits[i] + carry;
           // digits[i] = (newval) % 10;
           // carry = bool((newval) / 10);
        }

        if(carry)
            digits.insert(digits.begin(), 1);

        return digits;
    }
};

int main() {
    Solution s;

    return 0;
}
