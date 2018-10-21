//
//@author Xiao Xu
//@create 2018-10-21 12:23
//Construct Binary Tree from Preorder and Inorder Traversal
//使用map查找inorder中元素更快
//

#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if(!inorder.size() || !preorder.size())
            return NULL;
        this->inorder = inorder;
        this->preorder = preorder;
        return buildTreeStep(0, preorder.size() - 1, 0, inorder.size() - 1);
    }

    TreeNode* buildTreeStep(int pre_begin, int pre_end, int in_begin, int in_end){
        auto *root = new TreeNode(this->preorder[pre_begin]);
        if(pre_begin < pre_end && in_begin < in_end){
            int tree_size = pre_end - pre_begin + 1;
            int rootIn = getPosition(this->preorder[pre_begin]), left_size = rootIn - in_begin, right_size = in_end - rootIn;
            if(rootIn != in_begin)
                root->left = buildTreeStep(pre_begin + 1, pre_begin + left_size, in_begin, rootIn - 1);
            if(rootIn != in_end)
                root->right = buildTreeStep(pre_begin + left_size + 1, pre_end, rootIn + 1, in_end);

        }
        return root;
    }

    int getPosition(int num){
        for(int i = 0; i <this->inorder.size(); i++){
            if(this->inorder[i] == num)
                return i;
        }
        return -1;
    }

private:
    vector<int> preorder;
    vector<int> inorder;
};

int main() {
    Solution s;
    vector<int> preorder = {3,9,20,15,7};
    vector<int> inorder = {9,3,15,20,7};
    auto root = s.buildTree(preorder, inorder);
    return 0;
}
