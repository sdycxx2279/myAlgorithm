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
/*
 * 通过set与遍历所有字母找change为1的单词
    for (int j = 0; j < word.size(); j++) {
        char c = word[j];
        for (int k = 0; k < 26; k++) {
            word[j] = 'a' + k;
            if (dict.find(word) != dict.end()) {
                todo.push(word);
            }
        }
        word[j] = c;
    }
*/

/*
 *
 * 最快做法，当候选字符串大小大于end字符串数量时，切换他们（如果待求下一层字符串的数量比end多时，我们改从反向end向上传递）
 * int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> bSet{beginWord};
        unordered_set<string> eSet{endWord};
        unordered_set<string> wSet(wordList.begin(),wordList.end());
        if(wSet.find(endWord) == wSet.end())
            return 0;
        int res = 1;

        while(!bSet.empty())
        {
            unordered_set<string> tSet;
            ++res;
            for(auto w : bSet)
            {
                wSet.erase(w);
            }
            for(auto word : bSet)
            {
                for(int i = 0;i < word.size();i++)
                {
                    string w = word;
                    for(auto j = 'a' ;j <= 'z';j++)
                    {
                        w[i] = j;
                        if(wSet.find(w) == wSet.end())
                        {
                            continue;
                        }
                        if(eSet.find(w) != eSet.end())
                        {
                            return res;
                        }
                        tSet.insert(w);
                    }
                }

            }
            if(tSet.size() >= eSet.size())
            {
                bSet = eSet;
                eSet = tSet;
            }
            else
            {
                bSet = tSet;
            }
        }
        return 0;
    }
 */
};

int main() {
    Solution s;

    return 0;
}
