//
//@author Xiao Xu
//@create 2018-10-03 17:26
//Binary Tree Zigzag Level Order Traversal
//使用reverse更快
//

#include <iostream>
#include <vector>
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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> result;
        if(root == NULL)
            return result;
        queue<TreeNode*> tree;
        bool inverted = false;
        tree.push(root);

        while(!tree.empty()){
            vector<int> temp(tree.size(), 0);
            int limited = tree.size();
            for(int i = 0; i < limited; i++){
                int pos;
                if(inverted)
                    pos = limited - i - 1;
                else
                    pos = i;
                TreeNode* t = tree.front();
                tree.pop();
                temp[pos] = t->val;
                if(t->left != NULL)
                    tree.push(t->left);
                if(t->right != NULL)
                    tree.push(t->right);
            }
            inverted = !inverted;
            result.push_back(temp);
        }
        return result;
    }
};

int main() {
    Solution s;

    return 0;
}
