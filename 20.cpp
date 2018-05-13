//
//@author Xiao Xu
//@create 2018-05-13 11:17
//Valid Parentheses
//处理右括号时忘记处理栈内无任何左括号情况
//

#include <iostream>
#include<stack>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        int length_s = s.size();
        stack<char> sta;
        bool valid = true;
        if(length_s == 0)
            return true;
        for(int i = 0; i < length_s && valid; i++){
            switch(s[i]){
                case '(':
                    sta.push(s[i]);
                    break;
                case ')':
                    if(!sta.empty() && sta.top() == '('){
                        sta.pop();
                    }else{
                        valid = false;
                    }
                    break;
                case '[':
                    sta.push(s[i]);
                    break;
                case ']':
                    if(!sta.empty() && sta.top() == '['){
                        sta.pop();
                    }else{
                        valid = false;
                    }
                    break;
                case '{':
                    sta.push(s[i]);
                    break;
                case '}':
                    if(!sta.empty() && sta.top() == '{'){
                        sta.pop();
                    }else{
                        valid = false;
                    }
                    break;
                default:
                    valid = false;
                    break;
            }
        }
        return valid && sta.empty();
    }
};

int main() {
    Solution s;

    return 0;
}
