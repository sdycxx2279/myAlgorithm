//
//@author Xiao Xu
//@create 2018-05-04 10:48
//Longest Common Prefix
//调试：两层循环只跳出一层（stupid）
//

#include<iostream>
#include <vector>

using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int strs_length = strs.size();
        if(strs_length == 0)
            return "";
        string prefix = strs[0];
        for(int i = 1; i < strs_length; i++){
            int prefix_length = prefix.size();
            int str_length = strs[i].size();
            for(int j = 1; j <= prefix_length; j++){
                if(j > str_length)
                    prefix = strs[i];
                if(prefix.substr(0,j) != strs[i].substr(0,j)){
                    if(j == 1){
                        prefix = "";
                    }else {
                        prefix = prefix.substr(0, j - 1);
                    }
                    break;
                }
            }
            if(prefix.empty())
                break;
        }
        return prefix;
    }
};

int main() {
    Solution s;
    vector<string> v = {"aac","ab"};
    cout<<s.longestCommonPrefix(v);
    return 0;
}
