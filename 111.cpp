//
//@author Xiao Xu
//@create 2018-10-31 21:10
//Minimum Depth of Binary Tree
//使用迭代更快，也更简便

#include<iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    int minDepth(TreeNode* root) {
        if(root == NULL)
            return 0;
        int depth = 1, num_layer = 1, nums = 0, next_layers = 0;
        queue<TreeNode*> tree;
        tree.push(root);

        while(!tree.empty()){
            root = tree.front();
            tree.pop();

            nums++;
            if(root->left == NULL && root->right == NULL)
                return depth;
            if(root->left != NULL){
                next_layers++;
                tree.push(root->left);
            }
            if(root->right != NULL){
                next_layers++;
                tree.push(root->right);
            }
            if(nums >= num_layer){
                nums = 0;
                depth++;
                num_layer = next_layers;
                next_layers = 0;
            }
        }
        return depth;
    }

//    if(!root) return 0;
//    if(!root->left && !root->right) return 1;
//    int mindepth = INT_MAX;
//    if(root->left) mindepth = min(mindepth, minDepth(root->left));
//    if(root->right) mindepth = min(mindepth, minDepth(root->right));
//    return mindepth+1;
};

int main(){
    Solution s;

    return 0;
}