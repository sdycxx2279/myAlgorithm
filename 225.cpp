//
//@author Xiao Xu
//@create 2018-10-19 15:29
//Implement Stack using Queues
//
//

#include <iostream>
#include <queue>

using namespace std;

class MyStack {
public:
    /** Initialize your data structure here. */
    MyStack() {

    }

    /** Push element x onto stack. */
    void push(int x) {
        int num = que.size();
        que.push(x);
        for(int i = 0; i < num; i++){
            que.push(que.front());
            que.pop();
        }
    }

    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        int x = que.front();
        que.pop();
        return x;
    }

    /** Get the top element. */
    int top() {
        return que.front();
    }

    /** Returns whether the stack is empty. */
    bool empty() {
        return que.empty();
    }
private:
    queue<int> que;
};

int main() {

    return 0;
}
