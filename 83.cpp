//
//@author Xiao Xu
//@create 2018-09-06 22:35
//Remove Duplicates from Sorted List
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
        if(head == NULL)
            return head;
        ListNode *i = head->next;
        ListNode *pointer = head;
        while(i != NULL){
            if(i->val != pointer->val){
                pointer->next = i;
                pointer = i;
            }
            i = i->next;
        }
        //一开始忘记处理结尾
        pointer->next = NULL;
        return head;
    }
};

int main() {
    Solution s;

    return 0;
}
