//
//@author Xiao Xu
//@create 2018-12-25 21:10
//Elimination Game
//学习自讨论区，一行代码解决的方法没看懂。。
//我们观察保留数列头，每次当从左开始或从右开始数列中剩余数量为奇数是头发生变化，
//每次删除数列中剩余数为n/2，当数列中仅有1个数时，头即为所求

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int lastRemaining(int n) {
        int remain = n, step = 1, head = 1;
        bool left = true;
        while(remain > 1){
            if(left || remain % 2 == 1){
                head += step;
            }
            remain = remain / 2;
            step = step * 2;
            left = !left;
        }
        return head;
    }
};

int main(){
    Solution s;

    return 0;
}