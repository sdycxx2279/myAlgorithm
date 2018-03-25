//
//@author Xiao Xu
//@create 2018-03-25 10:56
//
#include <iostream>
using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        int lengthOfStr = s.size();
        int posOfFirst = 0;
        int lengthOfSub = 0;
        int j,k;
        if(lengthOfStr == 0)
            return "";
        else if(lengthOfStr == 1)
            return s;
        for(int i = 0;i < lengthOfStr;i++){
            if(lengthOfSub >= 2*(lengthOfStr - i)){
                return s.substr(posOfFirst,lengthOfSub);
            }
            int count = 0;
            int positionNow = i;
            while(s[positionNow+1]==s[positionNow]){
                count++;
                positionNow++;
                if(positionNow >= lengthOfStr - 1)
                    break;
            }
            j = i;
            k = i+count;
            while(j > 0&&k < lengthOfStr-1){
                if(s[--j] != s[++k]){
                    k--;
                    j++;
                    break;
                }
            }
            if(lengthOfSub < k - j + 1){
                lengthOfSub = k - j + 1;
                posOfFirst = j;
            }
        }
        return s.substr(posOfFirst,lengthOfSub);
    }
};

int main(){
    Solution solution;
    string s = "csbbbsd";
    cout<<solution.longestPalindrome(s);
    return 0;
}

