//
//@author Xiao Xu
//@create 2018-10-23 20:58
//Implement Queue using Stacks
//使用两个栈，每次push时均要倒置一遍，不如再读取时将值倒置入新栈，再次push时推入旧栈

#include<iostream>
using namespace std;

class MyQueue {
public:
    /** Initialize your data structure here. */
    MyQueue() {

    }

    /** Push element x to the back of queue. */
    void push(int x) {
        while(!s1.empty()){
            s2.push(s1.top());
            s1.pop();
        }

        s1.push(x);
        while(!s2.empty()){
            s1.push(s2.top());
            s2.pop();
        }
    }

    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        int num = s1.top();
        s1.pop();
        return num;
    }

    /** Get the front element. */
    int peek() {
        return s1.top();
    }

    /** Returns whether the queue is empty. */
    bool empty() {
        return s1.empty();
    }

private:
    stack<int> s1, s2;
};

int main(){
    Solution s;

    return 0;
}

