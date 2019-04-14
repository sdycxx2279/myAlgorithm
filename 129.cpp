//
//@author Xiao Xu
//@create 2019-04-12 14:10
//Sum Root to Leaf Numbers
//二叉树从根到叶子结点的数字（仅包括0～9）可以组成一个数字，求树中所有这种数字的和
//例：1->2->3组成123
//先序遍历求解即可

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
    int sumNumbers(TreeNode* root) {
        int sum = 0;
        dfs(root, sum, 0);
        return sum;
    }

    void dfs(TreeNode* root, int &sum, int num){
        if(root == nullptr)
            return ;
        num = num * 10 + root->val;
        if(root->left == nullptr && root->right == nullptr){
            sum += num;
            return ;
        }
        dfs(root->left, sum, num);
        dfs(root->right,sum, num);
    }
};

int main(){
    Solution s;

    return 0;
}
