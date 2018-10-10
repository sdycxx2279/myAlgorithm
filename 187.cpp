//
//@author Xiao Xu
//@create 2018-10-09 22:33
//Repeated DNA Sequences
//学习自讨论区，不包含字符串短于10的情况
//

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        vector<string> result;
        unordered_map<int, int> m;
        int t = 0;
        for(int i = 0; i < 9; i++){
            t = t << 3 | (s[i] & 7);
        }

        for(int i = 9; i < s.size(); i++){
            t = t << 3 & 0x3FFFFFFF | (s[i] & 7);
            if(m[t]++ == 1)
                result.push_back(s.substr(i - 9, 10));
        }

        return result;
    }
};

int main() {
    Solution s;

    return 0;
}
