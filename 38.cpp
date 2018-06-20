//
//@author Xiao Xu
//@create 2018-06-20 17:07
//Count and Say
//
//

#include <iostream>
#include <cstdlib>

using namespace std;

class Solution {
public:
    string countAndSay(int n) {
        string result = "1";
        char ch;
        string temp_result;
        int ch_num;
        for(int i = 1 ; i < n; i++){
            temp_result = "";
            ch_num = 1;
            ch = result[0];
            for(int j = 1; j < result.size(); j++){
                if(result[j] == ch){
                    ch_num++;
                }else{
                    temp_result += (ch_num + '0');
                    temp_result += ch;
                    ch_num = 1;
                    ch = result[j];
                }
            }
            temp_result += (ch_num + '0');
            temp_result += ch;
            result = temp_result;
        }
        return result;
    }
};

int main() {
    Solution s;
    cout<<s.countAndSay(5);
    return 0;
}
