//
//@author Xiao Xu
//@create 2018-10-16 23:11
//Isomorphic Strings
//

#include<iostream>
#include<vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int s_length = s.size();
        unordered_map<char, char> m_s, m_t;
        for(int i = 0; i < s_length; i++){
            if(!m_s.count(s[i]) && !m_t.count(t[i])){
                m_s[s[i]] = t[i];
                m_t[t[i]] = s[i];
            }else if(!m_s.count(s[i]) || !m_t.count(t[i])){
                return false;
            }else if(m_s[s[i]] != t[i] || m_t[t[i]] != s[i])
                return false;
        }
        return true;
    }
};

int main(){
    Solution s;

    return 0;
}





