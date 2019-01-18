//
//@author Xiao Xu
//@create 2019-01-14 21:10
//Add Strings
//
//

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    string addStrings(string num1, string num2) {
        int add = 0, i, j;
        string res;

        for(i = num1.size() - 1, j = num2.size() - 1; i >= 0 && j >= 0; i--, j--){
            int num = (num1[i] - '0') + (num2[j] - '0') + add;
            add = num / 10;
            num = num % 10;
            string temp = "";
            temp += (num + '0');
            res = temp + res;
        }

        while(i >= 0 && add){
            int num = (num1[i] - '0') + add;
            add = num / 10;
            num = num % 10;
            string temp = "";
            temp += (num + '0');
            res = temp + res;
            i--;
        }

        while(j >= 0 && add){
            int num = (num2[j] - '0') + add;
            add = num / 10;
            num = num % 10;
            string temp = "";
            temp += (num + '0');
            res = temp + res;
            j--;
        }

        if(add){
            res = "1" + res;
        }
        if(i >= 0){
            res = num1.substr(0, i + 1) + res;
        }
        if(j >= 0){
            res = num2.substr(0, j + 1) + res;
        }

        return res;
    }

    //减少代码量
    //if (num1.size() < num2.size()) return addStrings(num2, num1);
};

int main(){
    Solution s;

    return 0;
}