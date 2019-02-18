//
//@author Xiao Xu
//@create 2019-01-21 21:10
//Delete Node in a BST
//
//

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
    TreeNode* deleteNode(TreeNode* root, int key) {
        TreeNode *poi = root, *last = NULL;
        while(poi != NULL && poi->val != key){
            last = poi;
            if(poi->val < key)
                poi = poi->right;
            else
                poi = poi->left;
        }
        if(poi == NULL)
            return root;

        if(last == NULL && (root->left == NULL || root->right == NULL)){
            return root->left == NULL ? root->right : root->left;
        }else if(poi->left == NULL || poi->right == NULL){
            TreeNode *temp = poi->left == NULL ? poi->right : poi->left;
            if(last->left == poi)
                last->left = temp;
            else
                last->right = temp;
        }else{
            TreeNode *temp = poi->right;
            if(last != NULL){
                if(last->left == poi)
                    last->left = temp;
                else
                    last->right = temp;
            }else{
                root = temp;
            }
            while(temp->left != NULL)
                temp = temp->left;
            temp->left = poi->left;
        }

        return root;
    }
};
/*

TreeNode* findSuccessor (TreeNode* root) {
    auto t = root->right;
    while (t&&t->left) t = t->left;
    return t;
}
public:
TreeNode* deleteNode(TreeNode* root, int key) {
    if (not root) return root;
    if (key==root->val) {
        if (not root->left) return root->right;
        if (not root->right) return root->left;
        auto p = findSuccessor(root);
        root->val = p->val;
        root->right = deleteNode(root->right, p->val);
        return root;
    } else if (key<root->val) root->left = deleteNode(root->left, key);
    else root->right = deleteNode(root->right, key);
    return root;
}
 */

int main(){
    Solution s;

    return 0;
}