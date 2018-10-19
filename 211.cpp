//
//@author Xiao Xu
//@create 2018-10-16 23:14
//Add and Search Word - Data structure design
//

#include<iostream>
#include<vector>
#include <memory.h>
using namespace std;

class TrieNode{
public :
    TrieNode* children[26];
    bool is_word;
    TrieNode(){
        memset(this->children, 0, sizeof(children));
        this->is_word = false;
    }
};

class WordDictionary {
public:
    /** Initialize your data structure here. */
    WordDictionary() {
        this->root = new TrieNode();
    }

    /** Adds a word into the data structure. */
    void addWord(string word) {
        TrieNode *poi = root;
        for(int i = 0; i < word.size(); i++){
            if(poi->children[word[i] - 'a'] == NULL)
                poi->children[word[i] - 'a'] = new TrieNode();
            poi = poi->children[word[i] - 'a'];
        }
        poi->is_word = true;
    }

    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    bool search(string word) {
        return searchFromPoi(word, 0, this->root);
    }

    bool searchFromPoi(string word, int pos, TrieNode *poi){
        if(pos == word.size())
            return poi->is_word;
        for(int i = pos; i < word.size(); i++){
            if(word[i] == '.'){
                for(int j = 0; j < 26; j++){
                    if(poi->children[j] != NULL && searchFromPoi(word, i+1, poi->children[j]))
                        return true;
                }
                return false;
            }else{
                if(poi->children[word[i] - 'a'] == NULL)
                    return false;
                poi = poi->children[word[i] - 'a'];
            }

        }
        return poi->is_word;
    }

private:
    TrieNode *root;
};

int main(){

    return 0;
}