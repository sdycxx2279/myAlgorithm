//
//@author Xiao Xu
//@create 2018-06-24 22:27
//Combination Sum II
//将累加和与target比较转化为不断从target中减去数，大大降低运行时间
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        if(target == 0){
            return result;
        }
        vector<int> temp_result;
        sort(candidates.begin(), candidates.end());
        getSum(result, temp_result, candidates, 0, target);
        return result;
    }

    void getSum(vector<vector<int>>& result, vector<int> temp_result, vector<int>& candidates, int posi, int target) {
        if (target == 0) {
            result.push_back(temp_result);
        } else {
            for (int i = posi; i < candidates.size() && candidates[i] <= target; i++) {
                vector<int> next_result = temp_result;
                next_result.push_back(candidates[i]);
                getSum(result, next_result, candidates, i + 1, target - candidates[i]);
                //优化：避免溢出
                while (candidates[i] == candidates[i + 1] && i < candidates.size() - 1) {
                    i++;
                }
            }
        }
    }

        //原始版本
//        void getSum(vector<vector<int>>& result, vector<int> temp_result, vector<int>& candidates, int posi, int temp_sum, int target){
//            if(temp_sum == target){
//                result.push_back(temp_result);
//            }else if(temp_sum < target){
//                for(int i = posi; i < candidates.size(); i++){
//                    vector<int> next_result = temp_result;
//                    next_result.push_back(candidates[i]);
//                    getSum(result, next_result, candidates, i + 1, temp_sum + candidates[i], target);
//                    //优化：避免溢出
//                    while(candidates[i] == candidates[i+1] && i < candidates.size() - 1){
//                        i++;
//                    }
//                }
//            }
//        }
 //   }
};

int main() {
    Solution s;
    vector<int> a = {10,1,2,7,6,1,5};
    s.combinationSum2(a, 8);
    return 0;
}
