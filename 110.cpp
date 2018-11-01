//
//@author Xiao Xu
//@create 2018-10-31 21:10
//Balanced Binary Tree
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
    bool isBalanced(TreeNode* root) {
        return height_tree(root) >= 0;
    }

    int height_tree(TreeNode* root){
        if(root == NULL)
            return 0;
        int left_height = height_tree(root->left);
        if(left_height < 0)
            return -1;
        int right_height = height_tree(root->right);
        if(right_height < 0)
            return -1;
        //使用abs(l - r)更简便
        return max(left_height, right_height) - min(left_height, right_height) <= 1 ? max(left_height, right_height) + 1: -1;

    }
};

int main(){
    Solution s;

    return 0;
}