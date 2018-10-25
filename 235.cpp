//
//@author Xiao Xu
//@create 2018-10-25 21:54
//Lowest Common Ancestor of a Binary Search Tree
//
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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(p->val > q->val)
            return lowestCommonAncestor(root, q, p);
        if(root == p || root == q || (root->val > p->val && root->val < q->val))
            return root;
        else if(root->val > p->val && root->val > q->val)
            return lowestCommonAncestor(root->left, p, q);
        else
            return lowestCommonAncestor(root->right, p, q);
    }
};

int main() {
    Solution s;

    return 0;
}
