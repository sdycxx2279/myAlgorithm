//
//@author Xiao Xu
//@create 2019-04-26 18:10
//Binary Tree Right Side View
//统计二叉树每层最右边的节点，
//简单的BFS

#include<iostream>
#include<vector>
#include <queue>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;
        if(root == nullptr)
            return res;
        queue<TreeNode*> tree;
        tree.push(root);

        int child_num = 0, level = 1;
        while(!tree.empty()){
            root = tree.front();
            level--;
            tree.pop();

            if(root->left != nullptr){
                tree.push(root->left);
                child_num++;
            }
            if(root->right != nullptr){
                tree.push(root->right);
                child_num++;
            }
            if(!level){
                res.push_back(root->val);
                level = child_num;
                child_num = 0;
            }
        }

        return res;
    }
};

int main(){
    Solution s;

    return 0;
}