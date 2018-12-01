//
//@author Xiao Xu
//@create 2018-11-20 21:10
//Range Sum Query - Mutable
//树状数组

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    NumArray(vector<int> nums) {
        vector<int> v(nums.size() + 1, 0);
        for(int i = 0; i < nums.size(); i++){
            v[i+1] = nums[i];
        }

        for(int i = 1; i <= nums.size(); i++){
            int j = i + (i & -i);
            if(j < v.size())
                v[j] += v[i];
        }

        this->num = nums;
        this->arr = v;
    }

    void update(int i, int val) {
        int diff = this->num[i] - val;
        this->num[i++] = val;
        while(i < this->arr.size()){
            this->arr[i] -= diff;
            i = i + (i & -i);
        }
    }

    int prefix(int i){
        i++;
        int result = 0;
        while(i > 0){
            result += this->arr[i];
            i = i - (i & -i);
        }
        return result;
    }

    int sumRange(int i, int j) {
        return prefix(j) - prefix(i - 1);
    }

private:
    vector<int> num;
    vector<int> arr;
};

int main(){
    Solution s;

    return 0;
}