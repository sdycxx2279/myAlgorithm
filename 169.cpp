//
//@author Xiao Xu
//@create 2018-10-09 22:21
//Majority Element
//学习自讨论区，自己只想到hash table与排序两种方法
//随机选择一个元素，检查他是不是最优元素，如果不是，再重新找一个。据说这种方法最优。。。
//https://leetcode.com/problems/majority-element/discuss/51612/6-Suggested-Solutions-in-C++-with-Explanations

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count = 0, major;
        for(int i = 0; i < nums.size(); i++){
            if(count == 0){
                count++;
                major = nums[i];
            }
            else if(major == nums[i])
                count++;
            else
                count--;
        }
        return major;
    }
};

int main() {
    Solution s;

    return 0;
}
