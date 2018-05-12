//
//@author Xiao Xu
//@create 2018-05-12 21:10
//Remove Nth Node From End of List
//
//

#include <iostream>
#include<stack>
using namespace std;

struct ListNode {
         int val;
         ListNode *next;
         ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        stack<ListNode*> nodes;
        ListNode* pointer = head;
        ListNode *last, *now, *next;
        if(head == NULL)
            return head;
        while(pointer!=NULL){
            nodes.push(pointer);
            pointer = pointer->next;
        }
        now = NULL;
        for(int i = 0; i < n; i++){
            next = now;
            now = nodes.top();
            nodes.pop();
        }
        if(nodes.empty())
            return head->next;
        last = nodes.top();
        last->next = next;
        return head;
    }
};

int main() {
    Solution s;

    return 0;
}

//范例
//ListNode* removeNthFromEnd(ListNode* head, int n) {
//    // t2 用于 计数 t1 才是关键
//    ListNode** t1 = &head, *t2 = head;
//    for(int i = 1; i < n; ++i)
//    {
//        t2 = t2->next;
//
//    }
//
//    while(t2->next != NULL)
//    {
//        t1 = &((*t1)->next);
//        t2 = t2->next;
//    }
//    *t1 = (*t1)->next;
//
//    return head;
//
//}