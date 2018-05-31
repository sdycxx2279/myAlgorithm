//
//@author Xiao Xu
//@create 2018-05-31 10:16
//Longest Valid Parentheses
//
//

#include <iostream>
#include <stack>
using namespace std;

class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> st;
        int length_s = s.size();

        for(int i = 0; i < length_s;i++){
            if(s[i] == '('){
                st.push(i);
            }else if(s[i] == ')'){
                if(st.empty() || s[st.top()] != '('){
                    st.push(i);
                }else{
                    st.pop();
                }
            }
        }
        if(st.empty()){
            return length_s;
        }
        int end = length_s - 1;
        int length = 0;
        int now = 0;
        while(!st.empty()){
            now = st.top();
            st.pop();
            length = max(length, end - now);
            end = now - 1;
        }
        return max(length, end + 1);
    }
};

int main() {
    Solution s;
    cout<<s.longestValidParentheses("()(()");
    return 0;
}
