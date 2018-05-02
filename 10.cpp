//
//@author Xiao Xu
//@create 2018-04-03 13:49
//
#include<iostream>
using namespace std;

class Solution {
public:
    bool isMatch(string s,string p){
        int i = 0;
        int j = 0;
        int length_s = s.size();
        int length_p = p.size();
        char previous_p = ' ';
        while(i < length_s&&j < length_p){
            if(p[j] == '*'){
                if(previous_p != ' ' && s[i] == previous_p){
                    i++;
                    if(i == length_s){
                        j++;
                    }
                }else{
                    j++;
                }
            }else if(p[j] == '.'){
                if(j + 1 < length_p && p[j+1] == '*'){
                    if(j + 2 < length_p && p[j+2] == s[i]){
                        j += 2;
                    }else{
                        if(i == length_s - 1)
                            j += 2;
                    }
                    i++;
                }else{
                    previous_p = s[i];
                    i++;
                    j++;
                }
            }else{
                if(s[i] == p[j]){
                    i++;
                    previous_p = p[j];
                    j++;
                }else if(j + 1 < length_p){
                    if(p[j+1] == '*'){
                        j += 2;
                        if(j == length_p){
                            i++;
                        }
                    }else{
                        return false;
                    }
                } else{
                    return false;
                }

            }
        }
        while(j + 1 < length_p){
            if(p[j+1] == '*'){
                j += 2;
            }else{
                return false;
            }
        }
        return i == length_s && j == length_p;
    }
};

int main(){
    Solution s;
    cout<<s.isMatch("aab","c*a*b");
    return 0;
}
