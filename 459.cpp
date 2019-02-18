//
//@author Xiao Xu
//@create 2019-02-16 21:10
//Repeated Substring Pattern
//
//

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        string sub = "";
        int i = 0;
        while(i != s.size()){
            if(sub == "" || s[i] != sub[0]){
                if(i + 1 > s.size() / 2)
                    return false;
                sub += s[i++];
                //cout<<0;
            }else{
                int j = 0;
                while(j < sub.size() && i < s.size() && sub[j] == s[i]){
                    j++;
                    i++;
                }
                if(j != sub.size()){
                    if(i == s.size())
                        return false;
                    i = sub.size() + 1;
                    sub = s.substr(0, sub.size() + 1);
                }else if(i != s.size() && sub[0] != s[i]){
                    i = sub.size() + 1;
                    sub = s.substr(0, sub.size() + 1);
                }

                //cout<<1;
            }
            //cout<<sub<<endl;
        }
        return sub != s;
    }

    /**
     * bool repeatedSubstringPattern(string s) {
        int i = 1, j = 0, n = s.size();
        vector<int> dp(n+1,0);
        while( i < s.size() ){
            if( s[i] == s[j] ) dp[++i]=++j;
            else if( j == 0 ) i++;
            else j = dp[j];
        }
        return dp[n]&&dp[n]%(n-dp[n])==0;
    }
     */
};

int main(){
    Solution s;

    return 0;
}