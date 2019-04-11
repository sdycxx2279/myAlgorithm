//
//@author Xiao Xu
//@create 2019-04-11 21:10
//Binary Tree Maximum Path Sum
//找到最大的路径和

#include<iostream>
#include<vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int maxPathSum(TreeNode* root) {
        this->res = INT_MIN;
        dfs(root);
        return this->res;
    }

    int dfs(TreeNode *root){
        if(root == nullptr)
            return 0;

        int left = max(0, dfs(root->left));
        int right = max(0, dfs(root->right));

        this->res = max(this->res, left + right + root->val);
        return max(left, right) + root->val;
    }
private:
    int res;
};

int main(){
    Solution s;

    return 0;
}