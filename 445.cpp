//
//@author Xiao Xu
//@create 2019-01-18 21:10
//Add Two Numbers II
//
//

#include<iostream>
#include<vector>
#include <stack>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        stack<ListNode*> s1, s2;
        int count1 = 0, count2 = 0;
        ListNode* poi = l1;
        while(poi != NULL){
            s1.push(poi);
            poi = poi->next;
            count1++;
        }

        poi = l2;
        while(poi != NULL){
            s2.push(poi);
            poi = poi->next;
            count2++;
        }
        if(count1 > count2)
            poi = getRes(s1, s2);
        else
            poi = getRes(s2, s1);

        return poi;
    }

    ListNode* getRes(stack<ListNode*> s1, stack<ListNode*> s2){
        int add = 0;
        ListNode *next = NULL, *now;

        while(!s2.empty()){
            int temp = s1.top()->val + s2.top()->val + add;
            add = temp / 10;
            now = new ListNode(temp % 10);
            now->next = next;
            next = now;
            s1.pop();
            s2.pop();
        }

        while(!s1.empty()){
            int temp = s1.top()->val + add;
            add = temp / 10;
            now = new ListNode(temp % 10);
            now->next = next;
            next = now;
            s1.pop();
        }

        if(add){
            now = new ListNode(1);
            now->next = next;
        }

        return now;
    }
};

int main(){
    Solution s;

    return 0;
}