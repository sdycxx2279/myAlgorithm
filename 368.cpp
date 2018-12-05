//
//@author Xiao Xu
//@create 2018-12-05 21:10
//Largest Divisible Subset
//学习自讨论区，dp算法
//可以维护两个数组，一个数组存储其前一个约数的位置，一个存储其最大的子集数

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        if(nums.empty()){
            vector<int> res;
            return res;
        }
        vector<vector<int>> res(nums.size(), vector<int>(0));
        res[0].push_back(nums[0]);
        sort(nums.begin(), nums.end());
        int max_set = 0;
        for(int i = 1; i < nums.size(); i++){
            for(int j = 0; j < i; j++){
                if(nums[i] % nums[j] == 0)
                    if(res[j].size() + 1 > res[i].size()){
                        res[i] = res[j];
                        res[i].push_back(nums[i]);
                    }
            }
            if(res[i].empty())
                res[i].push_back(nums[i]);
            if(res[i].size() > res[max_set].size())
                max_set = i;
        }

        return res[max_set];
    }
};

int main(){
    Solution s;

    return 0;
}