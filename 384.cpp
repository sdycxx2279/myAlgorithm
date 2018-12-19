//
//@author Xiao Xu
//@create 2018-12-19 21:10
//Shuffle an Array
//
//

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    Solution(vector<int> nums) {
        this->nums = nums;
    }

    /** Resets the array to its original configuration and return it. */
    vector<int> reset() {
        return this->nums;
    }

    /** Returns a random shuffling of the array. */
    vector<int> shuffle() {
        vector<int> res;
        vector<int> temp = this->nums;
        for(int i = temp.size(); i > 0 ; i--){
            int poi = rand() % i;
            swap(temp[i - 1], temp[poi]);
            res.emplace_back(temp[i - 1]);
        }

        return res;
    }
private:
    vector<int> nums;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(nums);
 * vector<int> param_1 = obj.reset();
 * vector<int> param_2 = obj.shuffle();
 */

int main(){
    Solution s;

    return 0;
}