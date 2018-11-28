//
//@author Xiao Xu
//@create 2018-11-21 21:10
//Maximum Product of Word Lengths
//学习自讨论区，使用二进制数表示是否出现过某字母

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int maxProduct(vector<string>& words) {
        if(words.size() <= 1)
            return 0;
        vector<int> mask(words.size(), 0);
        for(int i = 0; i < words.size(); i++){
            for(char c : words[i]){
                mask[i] |= 1 << (c - 'a');
            }
            //cout<<mask[i]<<" ";
        }
        int result = 0;
        for(int i = 0; i < words.size() - 1; i++){
            for(int j = i + 1; j < words.size(); j++){
                if(!(mask[i] & mask[j])){
                    result = max(result, int(words[i].size() * words[j].size()));
                }
            }
        }

        return result;
    }
};

int main(){
    Solution s;

    return 0;
}