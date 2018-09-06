//
//@author Xiao Xu
//@create 2018-09-06 22:35
//Partition List
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
    ListNode* partition(ListNode* head, int x) {
        ListNode l1(0), l2(0);
        ListNode *le = &l1, *gr = &l2;

        while(head != NULL){
            if(head->val < x){
                le->next = head;
                le = head;
            }else{
                gr->next = head;
                gr = head;
            }
            head = head->next;
        }

        le->next = l2.next;
        gr->next = NULL;

        return  l1.next;
    }
};

int main() {
    Solution s;

    return 0;
}
