//
//@author Xiao Xu
//@create 2018-10-11 22:20
//Implement Trie (Prefix Tree)
//字典树
//

#include <iostream>
#include <memory.h>

using namespace std;

class TrieNode{
public:
    TrieNode(){
        memset(this->next, 0, sizeof(next));
        this->is_word = false;
    }

    TrieNode** getNext(){
        return this->next;
    }

    void setNext(TrieNode *t, int i){
        this->next[i] = t;
    }

    bool  getIsWord(){
        return this->is_word;
    }

    void setIsWord(bool is_word){
        this->is_word = is_word;
    }
private:
    TrieNode *next[26];
    bool is_word;
};

class Trie {
public:
    /** Initialize your data structure here. */
    Trie() {
        this->root = new TrieNode();
    }

    /** Inserts a word into the trie. */
    void insert(string word) {
        TrieNode *poi = this->root;
        for (char i : word) {
            if(poi->getNext()[i - 'a'] == NULL)
                poi->setNext(new TrieNode, i - 'a');
            poi = poi->getNext()[i - 'a'];
        }
        poi->setIsWord(true);
    }

    /** Returns if the word is in the trie. */
    bool search(string word) {
        TrieNode *poi = root;
        for(char letter : word){
            if(poi->getNext()[letter - 'a'] == NULL)
                return false;
            poi = poi->getNext()[letter - 'a'];
        }

        return poi->getIsWord();
    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        TrieNode *poi = root;
        for(char letter : prefix){
            if(poi->getNext()[letter - 'a'] == NULL)
               return false;
            poi = poi->getNext()[letter - 'a'];
        }

        return true;
    }

private:
    TrieNode *root;
};

int main() {

    return 0;
}
