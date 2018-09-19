//
//@author Xiao Xu
//@create 2018-09-19 21:09
// Copy List with Random Pointer
//使用unordered_map两遍即可完成，但需要占用O(n)空间

#include <iostream>
#include <vector>

using namespace std;

struct RandomListNode {
    int label;
    RandomListNode *next, *random;
    RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
};

class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        RandomListNode *pos = head;
        while(pos != NULL){
            RandomListNode *dup = new RandomListNode(pos->label);
            dup->next = pos->next;
            pos->next = dup;
            pos = dup->next;
        }

        pos = head;
        while(pos != NULL){
            if(pos->random != NULL)
                pos->next->random = pos->random->next;
            pos = pos->next->next;
        }

        pos = head;
        RandomListNode l1(0);
        RandomListNode *dup = &l1;

        while(pos != NULL){
            dup->next = pos->next;
            dup = dup->next;
            pos->next = dup->next;
            pos = pos->next;
        }

        return l1.next;
    }
};

int main() {
    Solution s;

    return 0;
}

