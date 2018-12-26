//
//@author Xiao Xu
//@create 2018-12-26 21:10
//Random Pick Index
//水池抽样
//

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    Solution(vector<int> nums) {
        this->nums = nums;
    }

    int pick(int target) {
        int idx = -1, n = 0;
        for(int i = 0; i < this->nums.size(); i++){
            if(this->nums[i] != target)
                continue;
            if(!n){
                idx = i;
                n++;
            }else{
                n++;
                if(!(rand() % n))
                    idx = i;
            }


        }
        return idx;
    }
private:
    vector<int> nums;
};

int main(){
    Solution s;

    return 0;
}