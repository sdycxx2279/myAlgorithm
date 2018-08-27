//
//@author Xiao Xu
//@create 2018-08-22 21:11
// Word Break
//
//
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        if(s.size() == 0)
            return true;
        for(int i = 0; i < wordDict.size(); i++){
            bool isEqual = true;
            for(int j = 0; j < wordDict[i].size(); j++){
                if(s[j] != wordDict[i][j]){
                    isEqual = false;
                    break;
                }
            }
            if(isEqual && wordBreak(s.substr(wordDict[i].size()), wordDict))
                return true;
        }
        return false;
    }

    void quick_sort(int left, int right, vector<string>& wordDict){

    }
};

int main(){
    Solution s;

    return 0;
}
