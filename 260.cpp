//
//@author Xiao Xu
//@create 2018-11-06 21:10
//Single Number III
//从讨论区学习，异或整个数组，所有相同数字均被消除，剩余两个不相同数字的二进制数中
// 一定有某一位不相同，任选一位（本题选择最后一位），再次遍历整个数组，该位为1的异
// 或相加得到数1，该位为0的异或相加得到数2

#include<iostream>
using namespace std;

class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int result = 0;
        vector<int> n(2, 0);
        for(int num : nums){
            result ^= num;
        }

        //这样选取最后一位
        result &= -result;
        for(int num : nums){
            if(num & result){
                n[0] ^= num;
            }else{
                n[1] ^= num;
            }
        }

        return n;
    }
};

int main(){
    Solution s;

    return 0;
}