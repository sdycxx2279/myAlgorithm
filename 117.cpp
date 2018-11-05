//
//@author Xiao Xu
//@create 2018-11-17 21:10
//Populating Next Right Pointers in Each Node II
//

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
        if(root == NULL)
            return ;
        TreeLinkNode *layer_begin, *pre, *poi, *next_layer_begin;
        layer_begin = root;
        while(layer_begin){
            poi = layer_begin;
            pre = NULL;
            next_layer_begin = NULL;
            while(poi){
                if(poi->left && poi->right){
                    if(pre != NULL)
                        pre->next = poi->left;
                    poi->left->next = poi->right;
                    pre = poi->right;
                }else if(poi->left){
                    if(pre != NULL)
                        pre->next = poi->left;
                    pre = poi->left;
                }else if(poi->right){
                    if(pre != NULL)
                        pre->next = poi->right;
                    pre = poi->right;
                }
                if(next_layer_begin == NULL && (poi->left || poi->right)){
                    next_layer_begin = poi->left ? poi->left : poi->right;
                }

                poi = poi->next;
            }
            layer_begin = next_layer_begin;
        }
    }
};

int main(){
    Solution s;

    return 0;
}