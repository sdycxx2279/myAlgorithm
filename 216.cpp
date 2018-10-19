//
//@author Xiao Xu
//@create 2018-10-16 23:15
//Combination Sum III
//

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<vector<int> > combinationSum3(int k, int n) {
        vector<vector<int> > result;
        vector<int> comb;
        getCombination(result, comb, k, 1, n);

        return result;
    }

    void getCombination(vector<vector<int> > &result, vector<int> comb, int k, int n_begin, int n_end){
        if(k == 0 && n_end == 0)
            result.push_back(comb);
        if(n_end - n_begin + 1 < k || k == 0 || n_end < n_begin)
            return ;
        int real_end = n_end < 10 ? n_end : 9;
        for(int i = n_begin; i < real_end + 1; i++){
            vector<int> temp = comb;
            temp.push_back(i);
            getCombination(result, temp, k-1, i + 1, n_end - i);
        }
    }
};

int main(){
    Solution s;

    return 0;
}





