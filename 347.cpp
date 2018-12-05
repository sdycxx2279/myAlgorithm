//
//@author Xiao Xu
//@create 2018-12-05 21:10
//Top K Frequent Elements
//利用桶实现，每个出现次数为1个桶

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> m;
        for(int num : nums){
            m[num]++;
        }

        vector<vector<int>> bucket(nums.size() + 1, vector<int>(0));

        for(auto num : m){
            bucket[num.second].push_back(num.first);
        }

        vector<int> result;
        for(int i = nums.size(); i > 0 && result.size() < k; i--){
            for(int num : bucket[i]){
                result.push_back(num);
                if(result.size() == k)
                    break;
            }
        }

        return result;
    }
};

int main(){
    Solution s;

    return 0;
}