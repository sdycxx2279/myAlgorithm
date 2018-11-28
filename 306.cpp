//
//@author Xiao Xu
//@create 2018-11-19 21:10
//Additive Number
//

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    bool isAdditiveNumber(string num) {
        for(int i = 1; i <= num.size() / 2; i++){
            for(int j = 1; j <= (num.size() - i) / 2; j++){
                if(check(num.substr(0, i), num.substr(i, j), num.substr(i + j)))
                    return true;
            }
        }

        return false;
    }

    bool check(string num1, string num2, string result){
        if((num1.size() > 1 && num1[0] == '0') || (num2.size() > 1 && num2[0] == '0'))
            return false;
        string true_result = add(num1, num2);
        int m = true_result.size(), n = result.size();
        if(true_result == result)
            return true;
        if((n <= m) || true_result.compare(result.substr(0, m))!=0)
            return false;
        else return check(num2, true_result, result.substr(m));
    }

    string add(string num1, string num2){
        int m = num1.size() - 1, n = num2.size() - 1,carry = 0;
        string res;

        while(m >= 0 || n >= 0){
            int temp = (m >= 0 ? num1[m--] - '0' : 0) + (n >= 0 ? num2[n--] - '0' : 0) + carry;
            carry = temp / 10;
            res.push_back('0' + temp % 10);
        }

        if(carry){
            res.push_back('1');
        }

        reverse(res.begin(), res.end());
        return res;
    }
};

int main(){
    Solution s;

    return 0;
}