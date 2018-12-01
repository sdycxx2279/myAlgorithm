//
//@author Xiao Xu
//@create 2018-12-01 12:00
// Reverse Vowels of a String
//
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    string reverseVowels(string s) {
        int left = 0, right = s.size() - 1;
        while(left < right){
            if(!isVowel(s[left]))
                left++;
            else if(!isVowel(s[right]))
                right--;
            else
                swap(s[left++], s[right--]);
        }

        return s;
    }
    bool isVowel(char c){
        for(char vowel : this->vowels){
            if(vowel == c)
                return true;
        }
        return false;
    }
private:
    vector<char> vowels = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
};

int main() {
    Solution s;

    return 0;
}
