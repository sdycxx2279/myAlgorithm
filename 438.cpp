//
//@author Xiao Xu
//@create 2019-01-18 21:10
//Find All Anagrams in a String
//滑动窗口算法
//使用vector<int>,256长度更快

#include<iostream>
#include<vector>
#include <map>

using namespace std;

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int start = 0, end = 0;
        map<char, int> m, temp;
        vector<int> res;

        for(char c : p){
            m[c]++;
        }
        temp = m;

        while(end <= s.size()){
            if(end - start == p.size()){
                res.push_back(start);
                temp[s[start++]]++;
            }else if(end == s.size()){
                break;
            }else if(temp[s[end]]){
                temp[s[end++]]--;
            }else if(!temp[s[end]] && m[s[end]]){
                temp[s[start++]]++;
            }else{
                end++;
                start = end;
                temp = m;
            }

        }

        return res;
    }
};

int main(){
    Solution s;

    return 0;
}