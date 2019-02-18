//
//@author Xiao Xu
//@create 2019-01-21 21:10
//Find All Numbers Disappeared in an Array
//
//

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> res;
        int i = 0;
        while(i < nums.size()){
            if(nums[nums[i] - 1] != nums[i]){
                swap(nums[nums[i] - 1],  nums[i]);
            }else
                i++;
        }

        for(i = 0; i < nums.size(); i++){
            if(nums[i] != i + 1){
                res.emplace_back(i + 1);
            }
        }

        return res;
    }
};

int main(){
    Solution s;

    return 0;
}