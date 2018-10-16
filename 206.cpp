//
//@author Xiao Xu
//@create 2018-10-16 23:13
//Reverse Linked List
//

#include<iostream>
#include<vector>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode *l1 = new ListNode(1);
        while(head != NULL){
            ListNode *temp = head->next;
            head->next = l1->next;
            l1->next = head;
            head = temp;
        }
        return l1->next;
    }
};

int main(){
    Solution s;

    return 0;
}










