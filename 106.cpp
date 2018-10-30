//
//@author Xiao Xu
//@create 2018-10-30 21:10
//Construct Binary Tree from Inorder and Postorder Traversal
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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        this->inorder = inorder;
        this->postorder = postorder;
        return buildTreeStep(0, inorder.size() - 1, 0, postorder.size() - 1);
    }

    TreeNode* buildTreeStep(int in_begin, int in_end, int post_begin, int post_end){
        if(in_begin > in_end){
            return NULL;
        }
        TreeNode* root = new TreeNode(this->postorder[post_end]);
        int root_in = get_position(this->postorder[post_end], in_begin, in_end);
        int left_size = root_in - in_begin;
        root->left = buildTreeStep(in_begin, root_in - 1, post_begin, post_begin + left_size - 1);
        root->right = buildTreeStep(root_in + 1, in_end, post_begin + left_size, post_end - 1);
        return root;
    }

    int get_position(int val, int in_begin, int in_end){
        for(int i = in_begin; i <= in_end; i++){
            if(this->inorder[i] == val)
                return i;
        }
        return -1;
    }
private:
    vector<int> inorder;
    vector<int> postorder;
};

int main(){
    Solution s;

    return 0;
}