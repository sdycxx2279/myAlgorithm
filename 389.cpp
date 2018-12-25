//
//@author Xiao Xu
//@create 2018-12-25 21:10
//Find the Difference
//
//

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    char findTheDifference(string s, string t) {
        vector<int> alpa(26, 0);

        for(char c : s){
            alpa[c - 'a']++;
        }

        for(char c : t){
            if(alpa[c - 'a']-- == 0)
                return c;
        }
    }
};

int main(){
    Solution s;

    return 0;
}