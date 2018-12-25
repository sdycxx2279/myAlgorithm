//
//@author Xiao Xu
//@create 2018-12-25 21:10
//Is Subsequence
//忘记处理""。。。,一次WA
//

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    bool isSubsequence(string s, string t) {
        if(!s.size())
            return true;
        int i = 0;
        for(char c : t){
            if(c == s[i]){
                if(i++ == s.size() - 1)
                    return true;
            }
        }
        return false;
    }

//    reverse(s.begin(), s.end());
//    for (auto c : t) {
//        if (c == s.back()) {
//            s.pop_back();
//        }
//    }
//    return s.size() == 0;
};

int main(){
    Solution s;

    return 0;
}