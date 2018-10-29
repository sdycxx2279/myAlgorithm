//
//@author Xiao Xu
//@create 2018-10-29 21:09
//Valid Anagram
//使用长度为26的vector更快

#include<iostream>
using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size() != t.size())
            return false;
        unordered_map<char, int> m;
        for(int i = 0; i < s.size(); i++){
            m[s[i]]++;
        }
        for(int i = 0; i < t.size(); i++){
            if(!m[t[i]]--)
                return false;
        }
        return true;
    }
};

int main(){
    Solution s;

    return 0;
}



