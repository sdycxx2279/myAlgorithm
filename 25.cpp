//
//@author Xiao Xu
//@create 2018-05-17 10:40
//Reverse Nodes in k-Group
//通过讨论区学习了反转k个节点的方法
//

#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head == nullptr || head->next == nullptr || k == 1)
            return head;
        ListNode *pre = new ListNode(1);
        pre->next = head;
        ListNode *last, *nex, *now,*temp_pre;
        int nums = 0;
        while(head != nullptr){
            head = head->next;
            nums++;
        }
        temp_pre = pre;
        while(nums >= k){
            last = temp_pre->next;
            now = last->next;
            nex = now->next;
            for(int i = 1; i < k; i++){
                now->next = temp_pre->next;
                temp_pre->next = now;
                last->next = nex;
                now = nex;
                if(nex != nullptr)
                    nex = nex->next;
            }
            temp_pre = last;
            nums -= k;
        }
        return pre->next;
    }
};

int main() {
    Solution s;

    return 0;
}
