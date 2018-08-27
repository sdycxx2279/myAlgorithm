//
//@author Xiao Xu
//@create 2018-08-08 10:06
// Multiply Strings
//基于乘法基本原理，注意位数多时分散存储为数组，进位时可能产生进一步进位
//

#include <iostream>

using namespace std;

class Solution {
public:
    string multiply(string num1, string num2) {
        int num1_length = num1.size();
        int num2_length = num2.size();
        string result(num1_length + num2_length, '0');

        for(int i = num1_length - 1; i >= 0; i--){
            int carry = 0;
            for(int j = num2_length - 1; j >= 0; j--){
                int temp = (result[i + j + 1] - '0') + (num1[i] - '0') * (num2[j] - '0') + carry;
                //cout<<temp<<endl;
                result[i + j + 1] =  '0' + temp % 10;
                carry = temp / 10;
            }
            result[i] +=  carry;
        }

        int pos = result.find_first_not_of('0');
        if(string::npos != pos){
            return result.substr(pos);
        }
        return "0";
    }
};

int main(){
    Solution s;
    cout<<s.multiply("123", "456");
    return 0;
}