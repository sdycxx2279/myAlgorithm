//
//@author Xiao Xu
//@create 2018-09-16 23:10
//Validate Binary Search Tree
//对二叉搜索树理解不深，忘记处理相同结点，忘记左侧所有节点都必须比根节点小
//边缘条件不好处理，看了讨论区，将值变为节点
//

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
    bool isValidBST(TreeNode* root) {
        if(root == NULL)
            return true;
        return isBST(root->left, NULL, root) && isBST(root->right, root, NULL);
    }

    bool isBST(TreeNode* chlid, TreeNode* min_root, TreeNode* max_root){
        if(chlid == NULL)
            return true;
        if((min_root && chlid->val <= min_root->val) || (max_root && chlid->val >= max_root->val))
            return false;
        return isBST(chlid->left, min_root, chlid) && isBST(chlid->right, chlid, max_root);
    }
};

int main() {
    Solution s;

    return 0;
}
