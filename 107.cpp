//
//@author Xiao Xu
//@create 2018-10-30 21:10
//Binary Tree Level Order Traversal II
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
    vector<vector<int> > levelOrderBottom(TreeNode* root) {
        vector<vector<int> > result;
        if(root == NULL)
            return result;
        queue<TreeNode*> tree;
        int num = 1,next_num = 0;
        tree.push(root);
        vector<int> temp;

        while(!tree.empty()){
            num--;
            root = tree.front();
            temp.push_back(root->val);
            tree.pop();

            if(root->left != NULL){
                tree.push(root->left);
                next_num++;
            }
            if(root->right != NULL){
                tree.push(root->right);
                next_num++;
            }
            if(!num){
                result.insert(result.begin(), temp);
                temp.clear();
                num = next_num;
                next_num = 0;
            }
        }

        return result;
    }
};

int main(){
    Solution s;

    return 0;
}