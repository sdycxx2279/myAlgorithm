//
//@author Xiao Xu
//@create 2018-12-19 21:10
//Linked List Random Node
//学习自讨论区，Reservoir Sampling：
//
//Problem:
//Choose k entries from n numbers. Make sure each number is selected with the probability of k/n
//        Basic idea:
//Choose 1, 2, 3, ..., k first and put them into the reservoir.
//For k+1, pick it with a probability of k/(k+1), and randomly replace a number in the reservoir.
//For k+i, pick it with a probability of k/(k+i), and randomly replace a number in the reservoir.
//Repeat until k+i reaches n
#include<iostream>
#include<vector>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    /** @param head The linked list's head.
        Note that the head is guaranteed to be not null, so it contains at least one node. */
    Solution(ListNode* head) {
        this->head = head;
    }

    /** Returns a random node's value. */
    int getRandom() {
        ListNode* poi = this->head;;
        int res , i = 1;
        while(poi){
            int temp = rand() % i++;
            if(!temp)
                res = poi->val;
            poi = poi->next;
        }

        return res;
    }
private:
    ListNode* head;
};

int main(){
    Solution s;

    return 0;
}