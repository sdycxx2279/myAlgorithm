//
//@author Xiao Xu
//@create 2018-05-04 10:02
//Roman to Integer
//调试错误：忘记写return，自动返回1（stupid）
//
#include<iostream>
using namespace std;

class Solution {
public:
    int romanToInt(string s) {
        string strs[13] = {"M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"};
        int nums[13] = {1000,900,500,400,100,90,50,40,10,9,5,4,1};
        int result = 0, j = 0, s_length = s.size();
        for(int i = 0; i < 13 && j < s_length; i++){
            result += romanToIntNow(s, &j, strs[i], nums[i]);
        }
        return result;
    }

    int romanToIntNow(string s, int *j, string str,int num){
        int str_length = str.size(), s_length = s.size();
        int result = 0;
        bool isStr = true;
        while(isStr && *j < s_length){
            if(s.substr(*j, str_length) == str){
                result += num;
                *j += str_length;
            }else
                isStr = false;
        }
        return result;
    }
};

int main(){
    Solution s;
    string str = "LVIII";
    cout<<s.romanToInt(str);
    return 0;
}