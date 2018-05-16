//
//@author Xiao Xu
//@create 2018-05-16 10:27
//Swap Nodes in Pairs
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
    ListNode* swapPairs(ListNode* head) {
        if(head == NULL || head->next == NULL)
            return head;
        ListNode *first, *second, *last;
        first = head->next;
        head->next = first->next;
        first->next = head;
        last = head;
        head = first;
        first = last->next;
        while(first != NULL && first->next != NULL){
            second = first->next;
            last->next = second;
            first->next = second->next;
            second->next = first;
            last = first;
            first = first->next;
        }
        return head;
    }
};

int main() {
    Solution s;

    return 0;
}
