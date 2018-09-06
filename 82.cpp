//
//@author Xiao Xu
//@create 2018-09-06 22:35
//Remove Duplicates from Sorted List II
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
    ListNode* deleteDuplicates(ListNode* head) {
        if(head == NULL || head->next == NULL)
            return head;
        ListNode l1(0);
        l1.next = head;
        ListNode *pre_head = &l1, *next = head->next;
        bool duplicate = false;

        while(next != NULL){
            if(head->val == next->val){
                duplicate = true;
            }else if(duplicate){
                pre_head->next = next;
                head = next;
                duplicate = false;
            }else{
                pre_head = head;
                head = next;
            }
            next = next->next;
        }

        if(duplicate)
            pre_head->next = next;
        return l1.next;
    }
};

int main() {
    Solution s;

    return 0;
}
