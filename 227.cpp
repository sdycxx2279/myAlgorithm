//
//@author Xiao Xu
//@create 2018-10-19 15:29
// Basic Calculator II
//先转换成逆波兰式，在计算（太慢）
//一个栈直接计算，将+与-变成数字的符号融入算式，第一遍只计算*与/，第二遍就将所有数字相加得到结果
//

#include <iostream>
#include <stack>

using namespace std;

class Solution {
public:
    int calculate(string s) {
        stack<string> s1, s2;
        stack<int> nums;
        bool is_num = false;
        //s1.push('#');
        for(int i = 0; i < s.size(); i++){
            if(s[i] == ' '){
                is_num = false;
                continue;
            }
            else if(s[i] == '+' || s[i] == '-'){
                is_num = false;
                while(!s1.empty()){
                    s2.push(s1.top());
                    s1.pop();
                }
                string str(1,s[i]);
                s1.push(str);
            }else if(s[i] == '*' || s[i] == '/'){
                is_num = false;
                while(!s1.empty() && (s1.top() == "*" || s1.top() == "/")){
                    s2.push(s1.top());
                    s1.pop();
                }
                string str(1,s[i]);
                s1.push(str);
            }else{
                if(is_num){
                    string temp = s2.top();
                    s2.pop();
                    s2.push(temp+s[i]);
                }else{
                    string str(1,s[i]);
                    s2.push(str);
                    is_num = true;
                }
            }
            //cout<<s2.top()<<endl;
        }

        while(!s2.empty()){
            s1.push(s2.top());
            s2.pop();
        }

        while(!s1.empty()){
            string now = s1.top();
            //cout<<now;
            s1.pop();
            if(now != "+" && now != "-" && now != "*" && now != "/"){
                nums.push(stringToNum(now));
            }else{
                int a = nums.top();
                nums.pop();
                int b = nums.top();
                nums.pop();
                if(now == "+"){
                    nums.push(a + b);
                }else if(now == "-"){
                    nums.push(b - a);
                }else if(now == "*"){
                    nums.push(a * b);
                }else{
                    nums.push(b / a);
                }
                //cout<<nums.top()<<endl;
            }
        }

        return nums.top();
    }

    int stringToNum(string s){
        int result = 0;
        for(int i = 0; i < s.size(); i++){
            result = result * 10 + (s[i] - '0');
        }
        return result;
    }
};

int main() {
    Solution s;

    return 0;
}
