//
//@author Xiao Xu
//@create 2018-12-19 21:10
//Ransom Note
//
//

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        vector<int> alpa(26, 0);
        for(char c : magazine){
            alpa[c - 'a']++;
        }

        for(char c : ransomNote){
            if(alpa[c - 'a']-- == 0)
                return false;
        }
        return true;
    }
};

int main(){
    Solution s;

    return 0;
}