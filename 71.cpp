//
//@author Xiao Xu
//@create 2018-08-31 15:53
//Simplify Path
//
//

#include <iostream>
#include <stack>
using namespace std;

class Solution {
public:
    string simplifyPath(string path) {
        stack<string> s;
        int last = 0;
        for(int i = 1; i < path.size(); i++){
            if(path[i] != '/')
                continue;
            else if(last != i - 1){
                string temp = path.substr(last, i - last);
                if(temp == "/.." && !s.empty())
                    s.pop();
                else if(temp != "/." && temp != "/.."){
                    s.push(temp);
                }
            }
            last = i;
        }
        if(last != path.size()-1){
            string temp = path.substr(last, path.size() - last);
            if(temp == "/.." && !s.empty())
                s.pop();
            else if(temp != "/." && temp != "/.."){
                s.push(temp);
            }
        }

        string result = "";
        while(!s.empty()){
            result = s.top() + result;
            s.pop();
        }
        if(!result.size())
            result = "/";

        return result;
    }
};

int main() {
    Solution s;

    return 0;
}
