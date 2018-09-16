//
//@author Xiao Xu
//@create 2018-09-14 15:34
//Palindrome Partitioning
//dfs更省时
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> result;
        vector<string> strs;
        this->str = s;
        getPartition(result, 0, 1, strs);
        return result;
    }

    void getPartition(vector<vector<string>>& result, int pos, int length, vector<string> strs){
        if(pos + length > this->str.size() && length == 1)
            result.push_back(strs);
        if(pos + length > this->str.size())
            return;
        getPartition(result, pos, length + 1, strs);

        string now_str = this->str.substr(pos, length);
        if(isPalindrome(now_str)){
            strs.push_back(now_str);
            getPartition(result, pos + length, 1, strs);
        }
    }

    bool isPalindrome(string s){
        int i = 0, j = s.size() - 1;
        while(i < j){
            if(s[i++] != s[j--])
                return false;
        }
        return true;
    }

private:
    string str;
};

int main() {
    Solution s;

    return 0;
}

//for(int i = begin; i < s.length(); ++i) {
//if(isPalindrome(s, begin, i)) {
//cur.push_back(s.substr(begin, i-begin+1));
//backtrack(s, i+1, cur, res);
//cur.pop_back();
//}
//}