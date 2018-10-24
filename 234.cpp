//
//@author Xiao Xu
//@create 2018-10-24 21:09
// Palindrome Linked List
//颠倒前半段并与后半段比较，不能视为O（1）空间复杂度算法

#include<iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if(head == NULL || head->next == NULL)
            return true;
        ListNode* l1 = new ListNode(0), *poi1 = head, *poi2 = head;
        bool is_more = false;

        while(poi2 != NULL){
            if(poi2->next == NULL)
                break;
            poi2 = poi2->next->next;
            poi1 = poi1->next;
        }
        if(poi2 != NULL){
            poi1 = poi1->next;
            is_more = true;
        }

        poi2 = head;

        while(poi1 != poi2){
            ListNode* temp = poi2->next;
            poi2->next = l1->next;
            l1->next = poi2;
            poi2 = temp;
        }

        poi2 = l1->next;
        if(is_more)
            poi2 = poi2->next;

        while(poi1 != NULL && poi2 != NULL){
            //cout<<poi1->val<<" "<<poi2->val<<endl;
            if(poi1->val != poi2->val)
                return false;
            poi1 = poi1->next;
            poi2 = poi2->next;
        }
        if(poi1 != NULL || poi2 != NULL)
            return false;
        return true;
    }
};

int main(){
    Solution s;

    return 0;
}

