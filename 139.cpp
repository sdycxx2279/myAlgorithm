//
//@author Xiao Xu
//@create 2018-08-23 22:40
//Word Break
//一开始没有使用动态规划，导致超时
//当需要-1状态时，可以使用0位置替代，整个数组后移一位
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int s_size = s.size();
        vector<bool> dp(s_size + 1, false);
        dp[0] = true;
        for(int i = 0; i < s_size + 1; i++){
            for(int j = 0; j < wordDict.size(); j++){
                if(dp[i] && i + wordDict[j].size() <= s_size){
                    string str = s.substr(i, wordDict[j].size());
                    if(str == wordDict[j])
                        dp[i + wordDict[j].size()] = true;
                }
                if(dp[s_size])
                    return true;
            }
        }

        return false;
    }
};

int main() {
    Solution s;

    return 0;
}
