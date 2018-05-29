//
//@author Xiao Xu
//@create 2018-05-29 9:50
//Substring with Concatenation of All Words
//学习unordered_map；滑动窗口遍历寻找子串
//

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> result;

        if(s.empty() || words.empty())
            return result;
        int length_s = s.size();
        int length_word = words[0].size();
        int num_words = words.size();
        unordered_map<string,int> words_map,temp_map;

        for(int i = 0; i < num_words;i++){
            if(words[i].size() != length_word)
                return result;
            if(words_map.find(words[i]) == words_map.end()){
                words_map[words[i]] = 1;
            }else{
                words_map[words[i]]++;
            }
        }
        int length_sub = length_word * num_words;
        for(int i = 0; i <= length_s - length_sub; i++){
            temp_map = words_map;
            bool succ = true;
            for(int j = i; j < i+length_sub;j+=length_word){
                string temp_string  = s.substr(j, length_word);
                if(temp_map.find(temp_string) == temp_map.end()){
                    succ = false;
                    break;
                }else if(temp_map[temp_string] == 0){
                    succ = false;
                    break;
                }else{
                    temp_map[temp_string]--;
                }
            }
            if(succ)
                result.push_back(i);
        }
        return result;
    }
};

int main() {
    Solution s;
    vector<string> str;
    str.push_back("foo");
    str.push_back("bar");
    vector<int> result = s.findSubstring("barfoothefoobarman", str);
    return 0;
}
