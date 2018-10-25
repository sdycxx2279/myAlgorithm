//
//@author Xiao Xu
//@create 2018-10-25 21:54
//Delete Node in a Linked List
//
//

#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    void deleteNode(ListNode* node) {
        ListNode* poi = node->next;

        while(poi != NULL){
            node->val = poi->val;
            poi = poi->next;
            if(poi != NULL)
                node = node->next;
            else
                node->next = NULL;
        }
    }

    //node->val = node->next->val;
    //node->next = node->next->next;
};

int main() {
    Solution s;

    return 0;
}
