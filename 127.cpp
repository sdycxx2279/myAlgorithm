//
//@author Xiao Xu
//@create 2018-09-14 15:32
//Word Ladder
//
//

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        vector<bool> traverse(beginWord.size(), false);

        return dfs(beginWord, endWord, wordList, traverse);
    }

    int bfs(string now, string endWord, vector<string>& wordList,vector<bool>& traverse){
        stack<string> word_stack;
        int length = 1;
        word_stack.push(now);

        while(!word_stack.empty() || !length){
            length++;
            now = word_stack.top();
            word_stack.pop();

            for(int i = 0; i < wordList.size(); i++){
                if(!traverse[i] && oneChanged(now, wordList[i])){
                    if(wordList[i] == endWord)
                        return  length;
                    traverse[i] = true;
                    word_stack.push(wordList[i]);
                }
            }
        }

        return 0;
    }

    int dfs(string now, string endWord, vector<string>& wordList,vector<bool>& traverse){
        if(now == endWord)
            return 1;
        int length = 0;
        for(int i = 0; i < wordList.size(); i++){
            if(!traverse[i] && oneChanged(now, wordList[i])){
                traverse[i] = true;
                int now_length = dfs(wordList[i], endWord, wordList, traverse);
                if(length == 0 && now_length != 0){
                    length = now_length + 1;
                }else if(length != 0 && now_length != 0){
                    length = min(length, now_length + 1);
                }
                traverse[i] = false;
            }
        }
        return length;
    }
    bool oneChanged(string a, string b){
        int changed = 0;
        for(int i = 0; i < a.size(); i++){
            if(a[i] != b[i])
                changed++;
        }

        return changed == 1;
    }
};

int main() {
    Solution s;

    return 0;
}
