//
//@author Xiao Xu
//@create 2018-09-13 22:41
//Linked List Cycle II
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
    ListNode *detectCycle(ListNode *head) {
        ListNode *fast = head, *slow = head;

        while(fast != NULL && fast->next != NULL){
            fast = fast->next->next;
            slow = slow->next;
            if(fast == slow){
                ListNode *poi = head;
                while(poi != slow){
                    poi = poi->next;
                    slow = slow->next;
                }
                return poi;
            }
        }
        return NULL;
    }
};

int main() {
    Solution s;

    return 0;
}
