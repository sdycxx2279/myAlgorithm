//
//@author Xiao Xu
//@create 2019-04-25 21:10
//Fraction to Recurring Decimal
//注意处理负数，负极限问题（转化为long）
//循环除，余数乘以十，直到待除数出现过一次为止

#include<iostream>
#include<vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        if(numerator == 0)
            return "0";
        string res = "";
        if(numerator > 0 ^ denominator > 0){
            res += "-";
        }
        long num = labs(numerator), div = labs(denominator);
        cout<<num<<" "<<div<<endl;
        unordered_map<long, int> m;
        res += (to_string(num / div));
        long r = num % div;
        if(!r)
            return res;
        res += ".";
        while(r){
            if(m[r] != 0){
                res.insert(m[r], "(");
                res += ")";
                break;
            }
            m[r] = res.size();
            r *= 10;
            res += to_string(r / div);
            r = r % div;
        }

        return res;
    }
};

int main(){
    Solution s;

    return 0;
}