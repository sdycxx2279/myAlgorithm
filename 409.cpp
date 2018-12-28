//
//@author Xiao Xu
//@create 2018-12-28 16:24
//Longest Palindrome
//
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int longestPalindrome(string s) {
        if(s.size() <= 1)
            return s.size();
        vector<int> low(26, 0);
        vector<int> upp(26, 0);

        for(char c : s){
            if(c >= 'a' && c <= 'z')
                low[c - 'a']++;
            else
                upp[c - 'A']++;
        }

        bool more = false;
        int res = 0;
        for(int i = 0; i < 26; i++){
            res += (low[i] / 2 + upp[i] / 2) * 2;
            if(low[i] % 2 || upp[i] % 2)
                more = true;
        }

        return more ? res + 1 : res;
    }
};

int main() {
    Solution s;

    return 0;
}
