//
//@author Xiao Xu
//@create 2018-11-07 21:10
//Missing Number
//参考讨论区（我为什么没想出来QAQ），将数组中数与0~n间全部数字异或，等同于一个数组中一个数有一个，其余所有数有两个的问题
//更快的方法，求0~n和（n*（n+1）/2），减去数组中所有数,剩余值即结果
//最快方法，遍历两遍数组，第一遍将数字存入对应位置，如1存入位置1，第二遍查看对应位置是否为正确数字，不正确则为所求值，两次遍历遇到n时特殊处理

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int result = 0;

        for(int i = 0; i < nums.size(); i++){
            result ^= nums[i];
            result ^= i;
        }
        result ^= nums.size();
        return result;
    }
};

int main(){
    Solution s;

    return 0;
}