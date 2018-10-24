//
//@author Xiao Xu
//@create 2018-10-24 21:09
//Count Complete Tree Nodes
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
    int countNodes(TreeNode* root) {
        if(root == NULL)
            return 0;
        TreeNode *lt = root->left, *rt = root->right;
        int l_length = 1, r_length = 1;
        while(lt != NULL){
            lt = lt->left;
            l_length++;
        }

        while(rt != NULL){
            rt = rt->right;
            r_length++;
        }

        if(l_length == r_length)
            return pow(2, l_length) - 1;

        return 1 + countNodes(root->left) + countNodes(root->right);
    }
};

int main(){
    Solution s;

    return 0;
}



