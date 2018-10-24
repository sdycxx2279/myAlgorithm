//
//@author Xiao Xu
//@create 2018-10-24 21:09
//Invert Binary Tree
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
    TreeNode* invertTree(TreeNode* root) {
        if(root != NULL){
            TreeNode* temp = root->left;
            root->left = invertTree(root->right);
            root->right = invertTree(temp);
        }
        return root;
    }
};

int main(){
    Solution s;

    return 0;
}

