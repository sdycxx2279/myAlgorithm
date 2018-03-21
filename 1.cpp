//
// Created by 26096 on 2018/3/20.
//
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int> &nums, int target) {
        vector<int> result;
        for(int i=0;i<nums.size();i++){
            int anot = target - nums[i];
            for(int j=i+1;j<nums.size();j++){
                if(anot == nums[j]){
                    result.push_back(i);
                    result.push_back(j);
                    return result;
                }
            }
        }
        return result;
    }
};

int main() {
    Solution s;
    int arr[] = {2,7,11,15};
    vector<int> v(begin(arr),end(arr));
    vector<int> result = s.twoSum(v,9);
    for(int i=0;i<result.size();i++){
        cout<<result[i]<<endl;
    }
    return 0;
}

