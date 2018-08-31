//
//@author Xiao Xu
//@create 2018-08-30 22:22
//Rotate List
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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == NULL)
            return head;
        int list_size = 1;
        ListNode *tail = head, *temp = head;


        while(tail->next){
            tail = tail->next;
            list_size++;
        }

        k = list_size - k % list_size - 1;
        for(int i = 0; i < k; i++){
            temp = temp->next;
        }
        tail->next = head;
        head = temp->next;
        temp->next = NULL;

        return head;
    }
};

int main() {
    Solution s;

    return 0;
}
