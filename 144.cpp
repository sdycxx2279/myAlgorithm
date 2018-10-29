//
//@author Xiao Xu
//@create 2018-10-29 21:09
//Binary Tree Preorder Traversal
//

#include<iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> result;
        stack<TreeNode*> tree;
        tree.push(root);

        while(!tree.empty()){
            root = tree.top();
            tree.pop();

            if(root == NULL)
                continue;
            result.push_back(root->val);
            tree.push(root->right);
            tree.push(root->left);
        }

        return result;
    }
};

int main(){
    Solution s;

    return 0;
}

