//
//@author Xiao Xu
//@create 2018-09-19 21:09
//Insertion Sort List
//使用一个pre节点可以提高速度

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
    ListNode* insertionSortList(ListNode* head) {
        if(head == NULL)
            return head;
        ListNode *pos = head->next, *last = head;

        while(pos != NULL){
            if(pos->val >= last->val){
                last = last->next;
                pos = pos->next;
            }else{
                ListNode *temp = pos->next;
                if(head->val >= pos->val){
                    pos->next = head;
                    head = pos;
                }else{
                    ListNode *poi = head;
                    while (poi->next->val < pos->val){
                        poi = poi->next;
                    }
                    pos->next = poi->next;
                    poi->next = pos;
                }
                pos = temp;
                last->next = temp;
            }
        }
        return head;
    }
};

int main() {
    Solution s;

    return 0;
}

