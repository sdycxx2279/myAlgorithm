//
//@author Xiao Xu
//@create 2019-04-16 21:10
//Binary Tree Postorder Traversal
//二叉树后序遍历，不使用递归
//记录树的子节点是否被遍历过，除非某节点为叶子节点，否则后序遍历之前的点必为其子节点

#include<iostream>
#include<vector>
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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;
        if(root == nullptr)
            return res;
        stack<TreeNode*> tree;
        tree.push(root);
        TreeNode* pre = nullptr;

        while(!tree.empty()){
            root = tree.top();

            if((root->left == nullptr && root->right == nullptr) || (pre != nullptr && (pre == root->right || (root->right == nullptr && pre == root->left)))){
                res.push_back(root->val);
                pre = root;
                tree.pop();
            }else if(root->left != nullptr && (pre == nullptr || pre != root->left)){
                tree.push(root->left);
            }else if(root->right != nullptr){
                tree.push(root->right);
            }
        }
        return res;
    }
};

int main(){
    Solution s;

    return 0;
}