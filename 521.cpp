//
//@author Xiao Xu
//@create 2019-04-17 11:10
//Longest Uncommon Subsequence I
//感觉出错了，没啥难度的一道题
//

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int findLUSlength(string a, string b) {
        if(a == b)
            return -1;
        return a.size() > b.size() ? a.size() : b.size();
    }
};

int main(){
    Solution s;

    return 0;
}