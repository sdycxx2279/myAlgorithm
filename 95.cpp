//
//@author Xiao Xu
//@create 2018-11-02 10:10
//Unique Binary Search Trees II
//DP算法，学习自讨论区，对n来讲，分两种情况，为root或其他最右结点。遍历n-1结果，将n作为root，原root作为左子树是一种情况，遍历所有右子树，将插入n后将原子树作为其左子树
//

#include <iostream>
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
    vector<TreeNode*> generateTrees(int n) {
        vector<TreeNode*> result;
        if(n < 1)
            return result;
        TreeNode* root = new TreeNode(1);
        result.push_back(root);

        for(int i = 2; i <= n; i++){
            vector<TreeNode*> temp;
            for(TreeNode* tree : result){
                root = new TreeNode(i);
                root->left = tree;
                temp.push_back(root);

                TreeNode* pos = tree;
                while(pos != NULL) {
                    TreeNode *tright = pos->right;
                    root = new TreeNode(i);
                    pos->right = root;
                    root->left = tright;
                    TreeNode* new_tree = clone(tree);
                    temp.push_back(new_tree);
                    pos->right = tright;
                    pos = tright;
                }
            }
            result = temp;
        }

        return result;
    }

    TreeNode* clone(TreeNode* root){
        if(root == NULL)
            return NULL;
        TreeNode* new_root = new TreeNode(root->val);
        new_root->left = clone(root->left);
        new_root->right = clone(root->right);

        return new_root;
    }
};

int main() {
    Solution s;

    return 0;
}
