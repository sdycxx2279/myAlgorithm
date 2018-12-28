//
//@author Xiao Xu
//@create 2018-12-28 16:24
//Sum of Left Leaves
//未处理空子树，WA
//

#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int sumOfLeftLeaves(TreeNode* root) {
        if(root == NULL)
            return 0;
        return getSum(root, false);
    }

    int getSum(TreeNode* root, bool left) {
        if(root->left == NULL && root->right == NULL){
            if(left)
                return root->val;
            else
                return 0;
        }
        int left_val = root->left ? getSum(root->left, true) : 0;
        int right_val = root->right ? getSum(root->right, false) : 0;

        return left_val + right_val;
    }
};

int main() {
    Solution s;

    return 0;
}
