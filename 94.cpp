//
//@author Xiao Xu
//@create 2018-09-09 16:55
// Binary Tree Inorder Traversal
//中序遍历，不使用递归
//

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;
        stack<TreeNode*> tree;
        while(root != NULL || !tree.empty()){
            if(root == NULL){
                root = tree.top();
                tree.pop();
                result.push_back(root->val);
                root = root->right;
            }
            else if(root->left == NULL){
                result.push_back(root->val);
                root = root->right;
            }else{
                tree.push(root);
                root = root->left;
            }

        }

        return result;
    }
};

int main() {
    Solution s;

    return 0;
}
