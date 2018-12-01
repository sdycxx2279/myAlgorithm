//
//@author Xiao Xu
//@create 2018-11-18 14:03
//Word Pattern
//双向映射
//

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    bool wordPattern(string pattern, string str) {
        unordered_map<char, string> m1;
        unordered_map<string, char> m2;
        int j = 0;
        for (int i = 0; i < pattern.size(); i++) {
            string word = "";
            while (str[j] == ' ')
                j++;
            while (j < str.size() && str[j] != ' ') {
                word += str[j++];
            }
            if (!m1.count(pattern[i]))
                m1[pattern[i]] = word;
            if (!m2.count(word))
                m2[word] = pattern[i];

            if (word == "" || m1[pattern[i]] != word || m2[word] != pattern[i])
                return false;
        }
        return j >= str.size();
    }
};

int main() {
    Solution s;

    return 0;
}
