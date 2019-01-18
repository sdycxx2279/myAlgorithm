//
//@author Xiao Xu
//@create 2019-01-14 21:10
//Minimum Genetic Mutation
//DFS
//

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int minMutation(string start, string end, vector<string>& bank) {
        vector<bool> use(bank.size(), false);

        int res = dfs(start, end, bank, use);

        return res == -2 ? -1 : res;
    }

    int dfs(string start, string end, vector<string>& bank, vector<bool>& use){
        if(start == end)
            return 0;
        int res = -1;
        for(int i = 0; i < bank.size(); i++){
            if(use[i])
                continue;
            if(isOne(start, bank[i])){
                use[i] = true;
                int temp = dfs(bank[i], end, bank, use) + 1;
                use[i] = false;
                if(temp != -1 && res != -1)
                    res = min(temp, res);
                else
                    res = max(temp, res);
            }
        }

        return res == -1 ? -2 : res;
    }

    bool isOne(string s1, string s2){
        int count = 0;
        for(int i = 0; i < 8; i++){
            if(s1[i] != s2[i])
                count++;
            if(count > 1)
                return false;
        }

        return count == 1;
    }
};

int main(){
    Solution s;

    return 0;
}