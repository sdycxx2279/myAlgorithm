#include <iostream>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

int main() {
    ListNode l = ListNode(1);
    ListNode* a = &l;
    a->val = 1;
    if(a->next)
        cout<<"a";
    else
        cout<<"b";
    return 0;
}