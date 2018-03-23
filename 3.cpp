//
//@author Xiao Xu
//@create 2018-03-22 9:17
//
#include<iostream>
#include <set>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int maxLength = 0;
        int positionOfBegin = 0;
        set<char> allCharSet;
        for(int i=0;i<s.length();i++){
            if(allCharSet.find(s[i]) != allCharSet.end()){
                maxLength = max(maxLength,i - positionOfBegin);
                positionOfBegin = s.find(s[i],positionOfBegin)+1;
                allCharSet.clear();
                for(int j = positionOfBegin;j<i;j++)
                    allCharSet.insert(s[j]);
            }
            allCharSet.insert(s[i]);
        }
        int i = s.length();
        maxLength = max(maxLength,i - positionOfBegin);
        return maxLength;
    }
};

int main(){
    Solution solution;
    string s = "abcabcbb";
    cout<<solution.lengthOfLongestSubstring(s);
    return 0;
}

