//
//@author Xiao Xu
//@create 2018-09-14 15:32
//Word Ladder
//简单bfs，根据层数求最短距离
//

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        vector<bool> traverse(wordList.size(), false);
        queue<string> q;
        q.push(beginWord);
        int res = 2,level = 1, next_level = 0;
        bool getRes = false;

        while(!q.empty() && !getRes){
            if(!level){
                level = next_level;
                next_level = 0;
                res++;
                //cout<<res<<endl;
            }
            level--;
            beginWord = q.front();
            q.pop();
            for(int i = 0; i < wordList.size(); i++){
                if(!traverse[i] && oneChanged(wordList[i], beginWord)){
                    if(wordList[i] == endWord){
                        getRes = true;
                        break;
                    }
                    //cout<<wordList[i]<<" ";
                    traverse[i] = true;
                    q.push(wordList[i]);
                    next_level++;
                }
            }
        }

        return getRes ? res : 0;
    }


    bool oneChanged(string a, string b){
        int changed = 0;
        for(int i = 0; i < a.size() && changed <= 1; i++){
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
