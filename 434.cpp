//
//@author Xiao Xu
//@create 2019-01-14 21:10
//Number of Segments in a String
//
//

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int countSegments(string s) {
        bool isSpace = true;
        int res = 0;
        for(char c : s){
            if(c != ' ' && isSpace){
                cout<<c<<" ";
                res++;
                isSpace = false;
            }else if(c == ' ' && !isSpace){
                isSpace = true;
            }
        }

        return res;
    }
};

int main(){
    Solution s;

    return 0;
}