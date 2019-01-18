//
//@author Xiao Xu
//@create 2019-01-18 21:10
//String Compression
//
//

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int compress(vector<char>& chars) {
        int poi = 1,count = 1;
        if(!chars.size())
            return 0;
        char prev = chars[0];
        for(int i = 1; i < chars.size(); i++){
            if(chars[i] == prev){
                count++;
            }
            else{
                if(count != 1){
                    string temp = to_string(count);
                    for(char c : temp){
                        chars[poi++] = c;
                    }
                }
                prev = chars[i];
                chars[poi++] = chars[i];
                count = 1;
            }
        }

        if(count != 1){
            string temp = to_string(count);
            for(char c : temp){
                chars[poi++] = c;
            }
        }
        return poi;
};

int main(){
    Solution s;

    return 0;
}