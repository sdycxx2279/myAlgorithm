//
//@author Xiao Xu
//@create 2019-01-14 21:10
//Flatten a Multilevel Doubly Linked List
//
//

#include<iostream>
#include<vector>
#include <stack>
using namespace std;

class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;

    Node() {}

    Node(int _val, Node* _prev, Node* _next, Node* _child) {
        val = _val;
        prev = _prev;
        next = _next;
        child = _child;
    }
};

class Solution {
public:
    Node* flatten(Node* head) {
        stack<Node*> n;
        Node *poi = head, *last = NULL;

        while(poi != NULL || !n.empty()){
            if(poi == NULL){
                poi = n.top();
                n.pop();
                last->next = poi;
                if(poi == NULL)
                    continue;
                poi->prev = last;

            }
            if(poi->child != NULL){
                n.push(poi->next);
                poi->child->prev = poi;
                poi->next = poi->child;
                poi->child = NULL;
            }
            if(poi->next == NULL){
                last = poi;
            }
            //cout<<poi->val<<" ";
            poi = poi->next;
        }

        return head;
    }
};

int main(){
    Solution s;

    return 0;
}