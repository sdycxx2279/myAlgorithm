//
//@author Xiao Xu
//@create 2018-06-21 10:06
// Combination Sum
//
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        sort(candidates.begin(),candidates.end());
        for(int i = 0; i < candidates.size(); i++){
            vector<int> temp_sum;
            temp_sum.push_back(candidates[i]);
            if(candidates[i] == target){
                result.push_back(temp_sum);
                break;
            }
            getSum(i, candidates[i], temp_sum, result, candidates, target);
        }
        return result;
    }

    void getSum(int posi, int temp, vector<int> temp_sum,  vector<vector<int>> &result, vector<int>& candidates, int target){
        for(int i = posi; i < candidates.size(); i++){
            if(temp + candidates[i] == target){
                temp_sum.push_back(candidates[i]);
                result.push_back(temp_sum);
                break;
            }else if(temp + candidates[i] > target){
                break;
            }else{
                vector<int> temp_result = temp_sum;
                temp_result.push_back(candidates[i]);
                getSum(i, temp + candidates[i], temp_result, result, candidates, target);
            }
        }
    }
};

int main() {
    Solution s;
    vector<int> a = {2,3,5};
    s.combinationSum(a, 7);
    return 0;
}
