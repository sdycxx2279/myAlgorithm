//
//@author Xiao Xu
//@create 2018-11-06 21:10
//Binary Tree Paths
//DFS求路径

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
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> result;
        if(root == NULL)
            return result;
        string str = "";
        getbinaryTreePaths(root, str, result);
        return result;
    }

    void getbinaryTreePaths(TreeNode* root, string str, vector<string>& result) {
        if(root == NULL)
            return ;

        if(str.empty())
            str += to_string(root->val);
        else
            str += ("->" + to_string(root->val));

        if(root->left == NULL && root->right == NULL){
            result.push_back(str);
            return ;
        }

        getbinaryTreePaths(root->left, str, result);
        getbinaryTreePaths(root->right, str, result);
    }
};

int main(){
    Solution s;

    return 0;
}

