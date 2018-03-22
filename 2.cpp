//
// Created by 26096 on 2018/3/22.
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        bool carry = false;
        bool first = true;
        ListNode *answer,*nowAnswer;
        while(l1 || l2 || carry){
            int val1 = l1 ? l1->val:0;
            int val2 = l2 ? l2->val:0;
            int a = val1 + val2;
            a = carry ? a+1:a;
            carry = a >= 10;
            l1 = l1 ? l1->next:l1;
            l2 = l2 ? l2->next:l2;
            if(first){
                answer = new ListNode(a % 10);
                nowAnswer = answer;
                first = false;
            }else{
                nowAnswer->next = new ListNode(a % 10);
                nowAnswer = nowAnswer->next;
            }
        }
        return answer;
    }
};

ListNode* init(vector<int> a){
    ListNode *l,*now;
    ListNode *temp = new ListNode(a[0]);
    l = temp;
    now = l;
    for(int i=1;i<a.size();i++){
        now->next = new ListNode(a[i]);
        now = now->next;
    }
    return l;
};

int main(){
    Solution s;
    vector<int> a1,a2;
    a1.push_back(2);
    a1.push_back(4);
    a1.push_back(3);
    a2.push_back(5);
    a2.push_back(6);
    a2.push_back(4);
    ListNode *l1 = init(a1);
    ListNode *l2 = init(a2);

    ListNode* l = s.addTwoNumbers(l1,l2);

    while(l){
        cout<< l->val<< endl;
        l = l->next;
    }
    return 0;
}

