//
//@author Xiao Xu
//@create 2018-12-25 21:10
//
//
//

#include<iostream>
#include<vector>
#include <stack>
using namespace std;

// This is the interface that allows for creating nested lists.
// You should not implement it, or speculate about its implementation
class NestedInteger {
public:
      // Constructor initializes an empty nested list.
      NestedInteger();

      // Constructor initializes a single integer.
      NestedInteger(int value);

      // Return true if this NestedInteger holds a single integer, rather than a nested list.
      bool isInteger() const;
      // Return the single integer that this NestedInteger holds, if it holds a single integer
      // The result is undefined if this NestedInteger holds a nested list
      int getInteger() const;

      // Set this NestedInteger to hold a single integer.
      void setInteger(int value);

      // Set this NestedInteger to hold a nested list and adds a nested integer to it.
      void add(const NestedInteger &ni);

      // Return the nested list that this NestedInteger holds, if it holds a nested list
      // The result is undefined if this NestedInteger holds a single integer
      const vector<NestedInteger> &getList() const;
};

class Solution {
public:
    NestedInteger deserialize(string s) {
        stack<NestedInteger> sta;
        for(int i = 0; i < s.size(); i++){
            if(s[i] == '['){
                NestedInteger n;
                sta.push(n);
            }else if(s[i] == ']' && i < s.size() - 1){
                NestedInteger n = sta.top();
                sta.pop();
                sta.top().add(n);
            }else if(s[i] == ']'){
                return sta.top();
            }else if(s[i] == ','){
                continue;
            }else{
                bool pos = true;
                if(s[i] == '-'){
                    pos = false;
                    i++;
                }
                int temp = 0;
                while(i < s.size() && s[i] <= '9' && s[i] >= '0'){
                    temp = temp * 10 + (s[i++] - '0');
                }
                temp = pos ? temp : -temp;
                i--;
                if(sta.empty()){
                    NestedInteger n(temp);
                    sta.push(n);
                }else
                    sta.top().add(temp);
            }
        }
        return sta.top();
    }
};

int main(){
    Solution s;

    return 0;
}
