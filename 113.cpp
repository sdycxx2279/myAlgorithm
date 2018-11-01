//
//@author Xiao Xu
//@create 2018-11-01 22:34
//Path Sum II
//使用一个temp，减少复制的时间与内存消耗
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
    vector<vector<int> > pathSum(TreeNode* root, int sum) {
        vector<vector<int> > result;
        vector<int> temp;
        getPath(result, temp, root, sum);
        return result;
    }

    void getPath(vector<vector<int> >& result, vector<int> temp, TreeNode* root, int sum) {
        if (root == NULL)
            return;
        temp.push_back(root->val);
        if (root->val == sum && root->left == NULL && root->right == NULL) {
            result.push_back(temp);
        } else {
            getPath(result, temp, root->left, sum - root->val);
            getPath(result, temp, root->right, sum - root->val);
        }
    }

    void help(TreeNode* root, int sum, vector<vector<int>>& res, vector<int>& vi) {
        if (!root) return;
        vi.push_back(root->val);
        if (!root->left && !root->right && root->val == sum) res.push_back(vi);
        help(root->left, sum - root->val, res, vi);
        help(root->right, sum - root->val, res, vi);
        vi.pop_back();  //remove vi.pop_back() if not reference
    }
};

int main() {
    Solution s;

    return 0;
}
