//
//@author Xiao Xu
//@create 2018-10-10 21:37
//
//
//

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

#include <iostream>
using namespace std;

class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode l1(0), *pre = &l1;
        l1.next == head;
        while(head != NULL){
            if(head->val == val)
                pre->next = head->next;
            else
                pre = head;
            head = head->next;
        }

        return l1.next;
    }
};

int main() {
    Solution s;

    return 0;
}
