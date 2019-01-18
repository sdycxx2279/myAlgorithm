//
//@author Xiao Xu
//@create 2019-01-14 21:10
//Longest Repeating Character Replacement
//
//

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int> v(26, 0);
        int max_count = 0, max_length = 0, start = 0, end = 0;

        while(end < s.size()){
            v[s[end] - 'A']++;
            max_count = max(max_count, v[s[end++] - 'A']);
            if(end  - start - max_count > k){
                v[s[start++] - 'A']--;
            }
            max_length = max(max_length, end - start);
        }

        return max_length;
    }
};

int main(){
    Solution s;

    return 0;
}