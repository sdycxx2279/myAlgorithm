//
//@author Xiao Xu
//@create 2018-10-30 21:10
//Convert Sorted Array to Binary Search Tree
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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return sortedArrayToBSTStep(nums, 0, nums.size() - 1);
    }

    TreeNode* sortedArrayToBSTStep(vector<int>& nums, int begin, int end) {
        if(begin > end)
            return NULL;
        if(begin == end)
            return new TreeNode(nums[begin]);
        int mid = (begin + end) / 2;
        TreeNode* root = new TreeNode(nums[mid]);
        root->left = sortedArrayToBSTStep(nums, begin, mid - 1);
        root->right = sortedArrayToBSTStep(nums, mid + 1, end);
        return root;
    }
};

int main(){
    Solution s;

    return 0;
}