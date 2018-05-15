//
//@author Xiao Xu
//@create 2018-05-14 9:19
//Generate Parentheses
//耗时太高
//

#include <iostream>
#include<stack>
#include<vector>
using namespace std;

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        stack<char> sta;
        vector<string> result, addLeft, addRight;

        if(n == 0)
            return result;
        addLeft = generate("", n, sta, true);
        result.insert(result.end(), addLeft.begin(), addLeft.end());

        return result;
    }

    vector<string> generate(string s, int n, stack<char> sta, bool left){
        vector<string> temp_result;
        if(n == 0){
            if(!left && !sta.empty()){
                sta.pop();
                s += ')';
                temp_result = generate(s, 0, sta, false);
            }else if(!left && sta.empty()){
                temp_result.push_back(s);
            }
            return temp_result;
        }
        if(left){
            sta.push('(');
            s += '(';
            n--;
        }else if(!sta.empty()){
            sta.pop();
            s += ')';
        }else{
            return temp_result;
        }
        vector<string> addLeft = generate(s, n, sta, true);
        vector<string> addRight = generate(s, n, sta, false);
        temp_result.insert(temp_result.end(), addLeft.begin(), addLeft.end());
        temp_result.insert(temp_result.end(), addRight.begin(), addRight.end());
        return temp_result;
    }

};

int main() {
    Solution s;

    return 0;
}



//范例
//vector<string> generateParenthesis(int n) {
//    vector<string> ret;
//    add(ret, "",n,n);
//    return ret;
//}
//void add(vector<string> & ret, string s,int left, int right){
//    if(left == 0 && right == 0){
//        ret.push_back(s);
//        return;
//    }
//    if(left > 0)
//        add(ret, s + "(",left-1, right);
//    if(right > left)
//        add(ret, s + ")", left, right-1);
//}
