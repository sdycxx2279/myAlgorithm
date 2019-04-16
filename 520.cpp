//
//@author Xiao Xu
//@create 2019-04-16 21:10
//Detect Capital
//判断大写字母用的是否有错误，没啥难度
//不过最优解法有点意思，用到了count_if函数

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    bool detectCapitalUse(string word) {
        bool cap = true, lower = true;
        for(int i = 0; i < word.size(); i++){
            if(word[i] >= 'a' && word[i] <= 'z'){
                if(lower)
                    cap = false;
                else
                    return false;
            }else if(i == 0){
                continue;
            }else if(!cap){
                return false;
            }else{
                lower = false;
            }
        }
        return true;
    }
};

/*
bool detectCapitalUse(string word) {
    int capCnt = count_if(word.begin(), word.end(), [](char c){return c <= 'Z';});
    return !capCnt || capCnt == word.size() || (capCnt == 1 && word[0] <= 'Z');
}
*/
int main(){
    Solution s;

    return 0;
}