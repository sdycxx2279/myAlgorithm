//
//@author Xiao Xu
//@create 2018-09-26 20:27
//Intersection of Two Linked Lists
//
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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *l1 = headA, *l2;
        int length1 = 0, length2 = 0, differ;

        while(l1 != NULL){
            length1++;
            l1 = l1->next;
        }

        l1 = headB;
        while(l1 != NULL){
            length2++;
            l1 = l1->next;
        }

        if(length1 > length2){
            l1 = headA;
            l2 = headB;
            differ = length1 - length2;
        } else{
            l2 = headA;
            l1 = headB;
            differ = length2 - length1;
        }

        for(int i = 0; i < differ; i++){
            l1 = l1->next;
        }

        while (l1 != NULL && l2 != NULL){
            if(l1 == l2)
                return l1;
            l1 = l1->next;
            l2 = l2->next;
        }

        return NULL;
    }
};

int main() {
    Solution s;

    return 0;
}


//ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
//{
//    ListNode *p1 = headA;
//    ListNode *p2 = headB;
//
//    if (p1 == NULL || p2 == NULL) return NULL;
//
//    while (p1 != NULL && p2 != NULL && p1 != p2) {
//        p1 = p1->next;
//        p2 = p2->next;
//
//        //
//        // Any time they collide or reach end together without colliding
//        // then return any one of the pointers.
//        //
//        if (p1 == p2) return p1;
//
//        //
//        // If one of them reaches the end earlier then reuse it
//        // by moving it to the beginning of other list.
//        // Once both of them go through reassigning,
//        // they will be equidistant from the collision point.
//        //
//        if (p1 == NULL) p1 = headB;
//        if (p2 == NULL) p2 = headA;
//    }
//
//    return p1;
//}

