//
//@author Xiao Xu
//@create 2018-11-18 14:03
//Longest Increasing Subsequence
//学习自讨论区，维护一个数组，每次若新的数最大，则将新的数插入尾部，否则取代数组中大于他的第一个数
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> res;
        for(int num : nums){
            auto it = lower_bound(res.begin(), res.end(), num);
            if(it == res.end())
                res.push_back(num);
            else
                *it = num;
        }
        return res.size();
    }
};

int main() {
    Solution s;

    return 0;
}
