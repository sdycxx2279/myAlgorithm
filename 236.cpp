//
//@author Xiao Xu
//@create 2018-10-25 21:54
//Lowest Common Ancestor of a Binary Tree
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
        if(root != NULL){
            TreeNode* lt = lowestCommonAncestor(root->left, p, q);
            TreeNode* rt = lowestCommonAncestor(root->right, p, q);
            if((root == p && (lt == q || rt == q)) || (root == q && (lt == p || rt == p)) || (lt == p && rt == q) || (lt == q && rt == p))
                return root;
            else if(root == p || root == q)
                return root;
            else if(lt != NULL)
                return lt;
            else if(rt != NULL)
                return rt;
        }
        return NULL;
    }
};

int main() {
    Solution s;

    return 0;
}
