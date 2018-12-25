//
//@author Xiao Xu
//@create 2018-12-25 21:10
//Longest Substring with At Least K Repeating Characters
//学习自讨论区，递归解决
//

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int longestSubstring(string s, int k) {
        if(s.size() < k || k <= 0)
            return 0;
        unordered_map<char, int> m;
        for(char c : s){
            m[c]++;
        }

        vector<int> invalid;
        for(int i = 0; i < s.size(); i++){
            if(m[s[i]] < k)
                invalid.push_back(i);
        }
        if(invalid.empty())
            return s.size();

        invalid.push_back(s.size());
        int res = 0, last = 0;
        for(int i = 0; i < invalid.size(); i++){
            res = max(longestSubstring(s.substr(last, invalid[i] - last), k), res);
            last = invalid[i] + 1;
        }

        return res;
    }
//排除掉一段错误答案
//    while (mid < n && count[s[mid]] >= k) ++mid;
//    if (mid == n) return n;
//    int left = longestSubstring(s.substr(0, mid), k);
//    while (mid < n && count[s[mid]] < k) ++mid;
//    int right = longestSubstring(s.substr(mid), k);
};

int main(){
    Solution s;

    return 0;
}