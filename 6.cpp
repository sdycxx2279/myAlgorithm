//
//@author Xiao Xu
//@create 2018-03-26 10:02
//Zigzag problem
//
#include<iostream>
using namespace std;

class Solution {
public:
    string convert(string s, int numRows) {
        int length = s.size();
        if(length <= numRows || numRows == 1)
            return s;
        string answer = "";
        int interval = 2 * numRows - 2;
        for(int i = 0;i < length;i += interval){
            answer += s[i];
        }
        for(int i = 1;i < numRows - 1;i++){
            int firstInterval = 2 * numRows - 2 * i - 2;
            for(int j = i;j < length; j += interval){
                answer += s[j];
                if(j + firstInterval >= length)
                    break;
                answer += s[j + firstInterval];
            }
        }
        for(int i = numRows-1;i < length;i += interval){
            answer += s[i];
        }
        return answer;
    }
};

int main(){
    Solution s;
    cout<<s.convert("AB",1);
    return 0;
}

