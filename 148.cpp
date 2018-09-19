//
//@author Xiao Xu
//@create 2018-09-19 21:09
// Sort List
//学习讨论区，采用归并排序，但不是完全理解为什么这样是O(nlogn)

#include <iostream>
#include <vector>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* sortList(ListNode* head) {
        if(head == NULL)
            return head;
        ListNode* pos = head;
        int length = 0;
        while(pos != NULL){
            pos = pos->next;
            length++;
        }

        ListNode l1(1);
        l1.next = head;
        for(int i = 1; i < length; i *= 2){
            pos = l1.next;
            ListNode* pre_head = &l1;

            while(pos != NULL){
                ListNode* second = split(pos, i);
                ListNode* temp = split(second, i);
                pre_head = merge(pos, second, pre_head);
                pos = temp;
            }
        }

        return l1.next;
    }

    ListNode* split(ListNode* start, int length){
        while (start != NULL && length > 1){
            start = start->next;
            length--;
        }
        if(start == NULL)
            return NULL;
        ListNode* second = start->next;
        start->next = NULL;
        return second;
    }

    ListNode* merge(ListNode* l1, ListNode* l2, ListNode* head){
        while (l1 != NULL && l2 != NULL){
            if(l1->val < l2->val){
                head->next = l1;
                l1 = l1->next;
            } else{
                head->next = l2;
                l2 = l2->next;
            }
            head = head->next;
        }

        head->next = l1 == NULL ? l2 : l1;
        while(head->next != NULL)
            head = head->next;
        return head;
    }
};

int main() {
    Solution s;

    return 0;
}

