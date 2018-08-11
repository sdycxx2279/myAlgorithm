//
//@author Xiao Xu
//@create 2018-08-08 10:06
// Multiply Strings
//debug中
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>

using namespace std;

class Solution {
public:
    string multiply(string num1, string num2) {
        int num1_length = num1.size();
        int num2_length = num2.size();
        long result = 0;
        string output;

        for(int i = num1_length - 1; i >= 0; i--){
            for(int j = num2_length - 1; j >= 0; j--){
                result += (num1[i] - '0') * (num2[j] - '0') * pow(10, (num1_length - i - 1) + (num2_length - j - 1));
            }
        }

        stringstream ss;
        ss<<result;
        ss>>output;

        return output;
    }
};

int main(){
    //Solution s;
    return 0;
}