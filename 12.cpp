//
//@author Xiao Xu
//@create 2018-05-03 10:16
//
#include<iostream>
using namespace std;

class Solution {
public:
    string intToRoman(int num) {
        string roman = "";
        roman += intToRomanNow(&num, 1000, "M");
        roman += intToRomanNow(&num, 900, "CM");
        roman += intToRomanNow(&num, 500, "D");
        roman += intToRomanNow(&num, 400, "CD");
        roman += intToRomanNow(&num, 100, "C");
        roman += intToRomanNow(&num, 90, "XC");
        roman += intToRomanNow(&num, 50, "L");
        roman += intToRomanNow(&num, 40, "XL");
        roman += intToRomanNow(&num, 10, "X");
        roman += intToRomanNow(&num, 9, "IX");
        roman += intToRomanNow(&num, 5, "V");
        roman += intToRomanNow(&num, 4, "IV");
        roman += intToRomanNow(&num, 1, "I");
        return roman;
    }

    string intToRomanNow(int *num, int now_num, string now_roman){
        string roman = "";
        int nums = *num / now_num;
        if(nums >= 1){
            for(int i = 0;i < nums; i++){
                roman += now_roman;
            }
            *num = *num % now_num;
        }
        return roman;
    }

};

int main(){
    Solution s;
    cout<<s.intToRoman(3999);
    return 0;
}
