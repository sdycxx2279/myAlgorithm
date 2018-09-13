//
//@author Xiao Xu
//@create 2018-09-13 22:36
//Reverse Linked List II
//直接走三个循环，一个到m之前，一个从m到n，一个n以后可以节省判断时间
//

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

#include <iostream>
using namespace std;

class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        ListNode l1(1);
        l1.next = head;
        ListNode *poi = &l1, *r_begin, *r_end, *temp;
        int length = 0;
        while(poi != NULL){
            if(length == m - 1){
                r_begin = poi;
                r_end = poi->next;
            }
            if(length > m &&  length <= n){
                temp = poi->next;
                poi->next = r_begin->next;
                r_begin->next = poi;
                poi = temp;
                if(length == n || poi == NULL)
                    r_end->next = poi;
            }else
                poi = poi->next;
            length++;
        }
        return l1.next;
    }
};

int main() {
    Solution s;

    return 0;
}
