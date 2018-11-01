//
//@author Xiao Xu
//@create 2018-10-31 21:10
//Convert Sorted List to Binary Search Tree
//

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
    TreeNode* sortedListToBST(ListNode* head) {
        if(head == NULL)
            return NULL;
        if(head->next == NULL)
            return new TreeNode(head->val);

        ListNode *fast = head, *slow = head, *last;
        while(fast != NULL && fast->next != NULL){
            last = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        last->next = NULL;
        fast = slow->next;
        TreeNode *root = new TreeNode(slow->val);
        root->left = sortedListToBST(head);
        root->right = sortedListToBST(fast);

        return root;
    }
};

int main(){
    Solution s;

    return 0;
}