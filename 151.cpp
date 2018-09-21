//
//@author Xiao Xu
//@create 2018-09-21 20:25
//Reverse Words in a String
//使用reverse函数，先转置整个字符串，在去掉多余空格，按单词分别转置即可
//resize（x）函数可以保留0~x的字符串
//

#include <iostream>
using namespace std;

class Solution {
public:
    void reverseWords(string &s) {
        string str = "", temp = "";
        bool flag = false;
        for(int i = 0; i < s.size(); i++){
            if(s[i] == ' ' && flag){
                flag = false;
                if(str == "")
                    str = temp;
                else
                    str = temp + " " + str;
                temp = "";
            }else if(s[i] != ' '){
                flag = true;
                temp += s[i];
            }
        }
        if(flag){
            if(str == "")
                str = temp;
            else
                str = temp + " " + str;
        }
        s = str;
    }
};

int main() {
    Solution s;

    return 0;
}
