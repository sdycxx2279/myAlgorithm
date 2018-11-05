//
//@author Xiao Xu
//@create 2018-11-17 21:10
//Populating Next Right Pointers in Each Node
//学习自讨论区，按照上一层的next广度优先遍历树

#include<iostream>
using namespace std;

struct TreeLinkNode {
    int val;
    TreeLinkNode *left, *right, *next;
    TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
};

class Solution {
public:
    void connect(TreeLinkNode *root) {
        if(root == NULL){
            return ;
        }
        TreeLinkNode *pre, *poi;
        pre = root;
        while(pre->left){
            poi = pre;
            while(poi){
                poi->left->next = poi->right;
                if(poi->next)
                    poi->right->next = poi->next->left;
                poi = poi->next;
            }
            pre = pre->left;
        }
    }
};

int main(){
    Solution s;

    return 0;
}