//
//@author Xiao Xu
//@create 2018-10-22 21:19
//Kth Smallest Element in a BST
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
    int kthSmallest(TreeNode* root, int k) {
        stack<TreeNode*> tree;
        tree.push(root);
        TreeNode* poi;
        int last_num = INT_MIN;

        while(!tree.empty()){
            poi = tree.top();
            while(poi->left != NULL && last_num < poi->left->val){
                poi = poi->left;
                tree.push(poi);
            }
            tree.pop();
            if(--k == 0)
                return poi->val;
            last_num = poi->val;
            if(poi->right != NULL){
                tree.push(poi->right);
            }
        }
        return 0;
    }
};

int main(){
    Solution s;

    return 0;
}

//while (!treeNode.empty() || curr) {
//if (curr) {
//treeNode.push(curr);
//curr = curr->left;
//} else {
//curr = treeNode.top();
//treeNode.pop();
//if (--k == 0)
//return curr->val;
//curr = curr->right;
//}
}
