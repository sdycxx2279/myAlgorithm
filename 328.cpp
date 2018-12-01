//
//@author Xiao Xu
//@create 2018-11-28 21:10
//Odd Even Linked List
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
    ListNode* oddEvenList(ListNode* head) {
        ListNode l1(0), l2(0), *p1 = &l1, *p2 = &l2;
        int i = 1;
        while(head != NULL){
            if(i % 2){
                p1->next = head;
                p1 = head;
            }else{
                p2->next = head;
                p2 = head;
            }
            i++;
            head = head->next;
        }
        p2->next = NULL;
        p1->next = l2.next;

        return l1.next;
    }
};

int main(){
    Solution s;

    return 0;
}