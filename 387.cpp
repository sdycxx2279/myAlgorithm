//
//@author Xiao Xu
//@create 2018-12-19 21:10
//First Unique Character in a String
//第二步可遍历alp，即第一次出现一次存储位置，出现两次及以上存储-2
//

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int firstUniqChar(string s) {
        vector<int> alp(26, 0);

        for(char c : s){
            alp[c - 'a']++;
        }

        for(int i = 0; i < s.size(); i++){
            if(alp[s[i] - 'a'] == 1)
                return i;
        }

        return -1;
    }
};

int main(){
    Solution s;

    return 0;
}