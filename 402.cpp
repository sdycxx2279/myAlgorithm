//
//@author Xiao Xu
//@create 2018-12-28 16:23
//Remove K Digits
//使用vector代替栈的作用应该更快
//

#include <iostream>
#include <algorithm>
#include <stack>

using namespace std;

class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<char> sta;
        for(int i = 0; i < num.size(); i++){
            while(k && !sta.empty() && sta.top() > num[i]){
                k--;
                sta.pop();
            }
            sta.push(num[i]);
        }


        while(!sta.empty() && k){
            k--;
            sta.pop();
        }

        string res;
        while(!sta.empty()){
            res += sta.top();
            sta.pop();
        }
        int i = res.size() - 1;
        while(res[i] == '0' && i >= 0){
            i--;
        }
        res = res.substr(0, i + 1);

        reverse(res.begin(), res.end());
        return res.size() ? res : "0";
    }
};

int main() {
    Solution s;

    return 0;
}
