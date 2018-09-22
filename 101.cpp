//
//@author Xiao Xu
//@create 2018-09-22 22:46
//Symmetric Tree
//空树为true
//使用栈进行遍历好像速度更快

#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if(root == NULL)
            return true;
        return treeSymmetric(root->left, root->right);
    }

    bool treeSymmetric(TreeNode* left, TreeNode* right){
        if(left == NULL && right == NULL)
            return true;
        if(left == NULL || right == NULL || left->val != right->val)
            return false;
        return treeSymmetric(left->left, right->right) && treeSymmetric(left->right, right->left);
    }
};

int main() {
    Solution s;

    return 0;
}
