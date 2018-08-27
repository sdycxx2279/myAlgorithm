//
//@author Xiao Xu
//@create 2018-08-25 20:57
//将字符串排序后作为键值，因为同字母字符串字符排序后相同
//
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> anagrams;
        for(string str : strs){
            string temp = str;
            sort(str.begin(), str.end());
            anagrams[str].push_back(temp);
        }
        vector<vector<string>> result;

        for(auto map : anagrams){
            result.push_back(map.second);
        }
        return result;
    }
};

int main() {
    Solution s;

    return 0;
}
