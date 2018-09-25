//
//@author Xiao Xu
//@create 2018-09-25 22:11
//Binary Tree Level Order Traversal
//在while循环里嵌套一层for循环，一次遍历本层所有节点
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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> result;
        if(root == NULL)
            return result;
        queue<TreeNode*> tree;
        tree.push(root);
        int i = 0, limited = 1, next_limited = 0;
        vector<int> v;
        while(!tree.empty()){
            if(i < limited){
                i++;
                TreeNode* t = tree.front();
                v.push_back(t->val);
                tree.pop();
                if(t->left != NULL){
                    tree.push(t->left);
                    next_limited++;
                }
                if(t->right != NULL) {
                    tree.push(t->right);
                    next_limited++;
                }
            }else{
                limited = next_limited;
                next_limited = 0;
                i = 0;
                result.push_back(v);
                v.clear();
            }
        }
        result.push_back(v);

        return result;
    }
};

int main() {
    Solution s;

    return 0;
}
