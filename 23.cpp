//
//@author Xiao Xu
//@create 2018-05-15 16:33
//Merge k Sorted Lists
//暴力过
//

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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int length_lists = lists.size();
        if(length_lists == 0)
            return NULL;
        ListNode *result = lists[0];
        for(int i = 1; i < length_lists; i++){
            result = mergeTwoLists(result, lists[i]);
        }
        return result;
    }

    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(!l1) return l2;
        if(!l2) return l1;
        if(!l1 && !l2) return NULL;

        ListNode *listNode, *begin;
        ListNode first = ListNode(1);
        listNode = &first;
        begin = listNode;
        while(l1 != NULL && l2 != NULL){
            if(l1->val <= l2->val){
                listNode->next = l1;
                l1 = l1->next;
            }else{
                listNode->next = l2;
                l2 = l2->next;
            }
            listNode = listNode->next;
        }
        if(l1 != NULL){
            listNode->next = l1;
        }
        if(l2 != NULL){
            listNode->next = l2;
        }
        return begin->next;
    }
};

int main() {
    Solution s;

    return 0;
}
