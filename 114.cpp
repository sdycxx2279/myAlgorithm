//
//@author Xiao Xu
//@create 2018-11-01 22:34
//Flatten Binary Tree to Linked List
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
    void flatten(TreeNode* root) {
        if(root == NULL)
            return ;
        this->poi = root;
        TreeNode *temp = root->right;
        dfs(root->left);
        dfs(temp);
    }

    void dfs(TreeNode* root){
        if(root == NULL)
            return ;
        this->poi->left = NULL;
        this->poi->right = root;
        this->poi = root;
        TreeNode *temp = root->right;
        dfs(root->left);
        dfs(temp);
    }
private:
    TreeNode* poi;
};

int main() {
    Solution s;

    return 0;
}
