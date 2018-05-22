//
//@author Xiao Xu
//@create 2018-05-22 10:44
//Implement strStr()
//KMP
//

#include <iostream>
using namespace std;

class Solution {
public:
    int strStr(string haystack, string needle) {
        if(needle.empty())
            return 0;
        if(haystack.empty())
            return -1;
        int length_h = haystack.size();
        int length_n = needle.size();
        int i = 0;
        int j = 0;
        int *next = new int[length_n];
        getNext(needle, next, length_n);
        while(i < length_h && j < length_n){
            if(j == -1 || haystack[i] == needle[j]){
                i++;
                j++;
            }else{
                j = next[j];
            }
        }
        if(j == length_n)
            return i - j;
        else
            return -1;
    }

    void getNext(string needle, int *next, int length_n){
        next[0] = -1;
        int k = -1;
        int i = 0;
        while(i < length_n){
            if (k == -1 || needle[i] == needle[k]) {
                k++;
                i++;
                next[i] = k;
            }
            else
                k = next[k];
        }
    }
};

int main() {
    Solution s;
    cout<<s.strStr("mississippi","issipi");
    return 0;
}
