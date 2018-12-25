//
//@author Xiao Xu
//@create 2018-12-25 21:10
//Decode String
//
//

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    string decodeString(string s) {
        stack<string> sta;
        bool beginNum = true;
        for(char c : s){
            if(c == '['){
                string t(1,c);
                sta.push(t);
            }
            else if(c == ']'){
                string temp1 = "";
                while(!sta.empty() && sta.top() != "["){
                    //cout<<temp<<" "<<sta.top()<<endl;
                    string temp2 = sta.top();
                    temp2 += temp1;
                    temp1 = temp2;
                    sta.pop();
                }
                string res = "";
                sta.pop();
                int times = getNum(sta.top());
                sta.pop();
                for(int i = 0; i < times; i++)
                    res += temp1;
                sta.push(res);
                beginNum = true;
            }else if(sta.empty() || sta.top() == "[" || beginNum){
                string t(1,c);
                sta.push(t);
                if(c >= '0' && c <= '9')
                    beginNum = false;
                else
                    beginNum = true;
            }else{
                string temp = sta.top();
                sta.pop();
                temp += c;
                sta.push(temp);
            }
        }

        string res = "";
        while(!sta.empty()){
            string temp = sta.top();
            temp += res;
            res = temp;
            sta.pop();
        }
        return res;
    }

    int getNum(string s){
        int res = 0;
        for(char c : s){
            res = res * 10 + (c - '0');
        }
        return res;
    }

//    string DFS(string s, int &k)
//    {
//        string ans;
//        int cnt = 0;
//        while(k < s.size())
//        {
//            if(isdigit(s[k])) cnt = cnt*10 + (s[k++]-'0');
//            else if(s[k]=='[')
//            {
//                string tem = DFS(s, ++k);
//                for(int i = 0; i < cnt; i++) ans += tem;
//                cnt = 0;
//            }
//            else if(s[k]==']')
//            {
//                k++;
//                return ans;
//            }
//            else ans += s[k++];
//        }
//        return ans;
//    }
//
//    string decodeString(string s) {
//        int k = 0;
//        return DFS(s, k);
//    }
};

int main(){
    Solution s;

    return 0;
}