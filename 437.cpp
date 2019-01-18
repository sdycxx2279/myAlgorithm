//
//@author Xiao Xu
//@create 2019-01-18 21:10
//Path Sum III
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
    int pathSum(TreeNode* root, int sum) {
        vector<int> path;

        return dfs(root, sum, 0, path);
    }

    int dfs(TreeNode* root, int sum, int level, vector<int>& path){
        if(root == NULL)
            return 0;
        int count = 0;
        for(int i = 0; i < level; i++){
            path[i] += root->val;
            if(path[i] == sum)
                count++;
        }
        if(root->val == sum)
            count++;
        if(level < path.size()){
            path[level] = root->val;
        }else
            path.push_back(root->val);

        count += dfs(root->left, sum, level + 1, path);
        count += dfs(root->right, sum, level + 1, path);
        for(int i = 0; i < level; i++){
            path[i] -= root->val;
        }

        return count;
    }
};

int main(){
    Solution s;

    return 0;
}