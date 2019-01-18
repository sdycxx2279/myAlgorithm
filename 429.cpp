//
//@author Xiao Xu
//@create 2019-01-14 21:10
//N-ary Tree Level Order Traversal
//
//

#include<iostream>
#include<vector>
#include <queue>
using namespace std;

class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> res;
        if(root == NULL)
            return res;

        int length = 1, next_length = 0;
        queue<Node*> q;
        q.push(root);
        vector<int> temp;

        while(!q.empty()){
            if(!length){
                length = next_length;
                next_length = 0;
                res.push_back(temp);
                temp.clear();
            }

            length--;
            Node* r = q.front();
            q.pop();
            temp.push_back(r->val);
            for(int i = 0; i < r->children.size(); i++){
                next_length++;
                q.push(r->children[i]);
            }
        }
        if(!temp.empty())
            res.push_back(temp);
        return res;
    }
};

int main(){
    Solution s;

    return 0;
}