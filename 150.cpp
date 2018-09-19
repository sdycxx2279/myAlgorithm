//
//@author Xiao Xu
//@create 2018-09-19 21:09
// Evaluate Reverse Polish Notation
//使用stoi函数更快

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        if(tokens.empty()){
            return 0;
        }

        stack<int> nums;
        int a, b;
        for(int i = 0; i < tokens.size(); i++){
            if(tokens[i] == "+"){
                a = nums.top();
                nums.pop();
                b = nums.top();
                nums.pop();
                nums.push(b + a);
            }else if(tokens[i] == "-"){
                a = nums.top();
                nums.pop();
                b = nums.top();
                nums.pop();
                nums.push(b - a);
            }else if(tokens[i] == "*"){
                a = nums.top();
                nums.pop();
                b = nums.top();
                nums.pop();
                nums.push(b * a);
            }else if(tokens[i] == "/"){
                a = nums.top();
                nums.pop();
                b = nums.top();
                nums.pop();
                nums.push(b / a);
            }else {
                int temp = 0, start = 0;
                if (tokens[i][0] == '-')
                    start = 1;
                for (int j = start; j < tokens[i].size(); j++) {
                    temp = temp * 10 + (tokens[i][j] - '0');
                }
                if (start)
                    temp = -temp;
                nums.push(temp);
            }
        }
        return nums.top();
    }
};

int main() {
    Solution s;

    return 0;
}

