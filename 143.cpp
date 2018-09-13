//
//@author Xiao Xu
//@create 2018-09-13 22:41
//Reorder List
//直接利用slow，fast两个指针o（n/2）找到中点，随后按原计划颠倒后半段链表，混序插入即可
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
    void reorderList(ListNode *head) {
        int length = 0, pos = 0;
        ListNode *end, *poi = head;
        while (poi != NULL) {
            poi = poi->next;
            length++;
        }

        poi = head;
        ListNode l1(0);
        while (poi != NULL) {
            if (pos < length / 2) {
                poi = poi->next;
            } else if (pos == length / 2) {
                ListNode *temp = poi->next;
                poi->next = NULL;
                poi = temp;
            } else {
                ListNode *temp = poi->next;
                poi->next = l1.next;
                l1.next = poi;
                poi = temp;
            }
            pos++;
        }

        end = l1.next;
        poi = head;
        while (poi != NULL && end != NULL) {
            ListNode *temp = end->next;
            end->next = poi->next;
            poi->next = end;
            poi = end->next;
            end = temp;
        }
    }
}

int main() {
    Solution s;

    return 0;
}
