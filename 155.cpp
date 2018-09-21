//
//@author Xiao Xu
//@create 2018-09-21 20:26
//Min Stack
//根据评论区学习通过两个栈实现
//

#include <iostream>
#include <stack>

using namespace std;

class MinStack {
public:
    /** initialize your data structure here. */
    MinStack() {

    }

    void push(int x) {
        s1.push(x);
        if(s2.empty() || x <= getMin())
            s2.push(x);
    }

    void pop() {
        if(getMin() == s1.top())
            s2.pop();
        s1.pop();
    }

    int top() {
        return s1.top();
    }

    int getMin() {
        return s2.top();
    }
private:
    stack<int> s1;
    stack<int> s2;
};

int main() {

    return 0;
}
