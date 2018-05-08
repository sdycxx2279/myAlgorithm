//
//@author Xiao Xu
//@create 2018-05-08 17:06
// Letter Combinations of a Phone Number
//未处理空值
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    string digitToNum[8] = {"abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
    vector<string> letterCombinations(string digits) {
        vector<string> result;
        if(digits.size() == 0){
            return result;
        }
        return getLetters(digits,"");
    }

    vector<string> getLetters(string digits, string prefix){
        vector<string> temp_string;
        if(digits.size() == 0){
            temp_string.push_back(prefix);
            return temp_string;
        }
        int num = digits[0] - '0';
        int length_letters = digitToNum[num - 2].size();
        digits = digits.substr(1,digits.size() - 1);
        for(int i = 0; i < length_letters; i++){
            string next_prefix = prefix;
            next_prefix.push_back(digitToNum[num - 2][i]);
            vector<string> next_string = getLetters(digits, next_prefix);
            temp_string.insert(temp_string.end(),next_string.begin(),next_string.end());
        }
        return temp_string;
    }
};

int main() {
    Solution s;
    vector<string> str = s.letterCombinations("23");
    return 0;
}
