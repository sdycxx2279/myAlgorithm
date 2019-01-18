//
//@author Xiao Xu
//@create 2019-01-18 21:10
// Find All Duplicates in an Array
//学习自讨论区，没注意到数组中数小于等于数组长度这一条件
//

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        for(int i = 0; i < nums.size();){
            if(nums[i] != nums[nums[i] - 1]){
                swap(nums[i], nums[nums[i] - 1]);
            }else
                i++;
        }
        vector<int> res;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] != i + 1)
                res.push_back(nums[i]);
        }

        return res;
    }
};

int main(){
    Solution s;

    return 0;
}