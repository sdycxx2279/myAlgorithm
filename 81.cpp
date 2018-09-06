//
//@author Xiao Xu
//@create 2018-09-06 22:34
//Submission Detail
//没必要遍历找出pivot，通过比较left，middle，right三指针的值可以找出pivot所在区间
//
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int m = nums.size();
        if(!m)
            return 0;
        int pivot = 0;
        for(int i = 0; i < m - 1; i++){
            if(nums[i] > nums[i+1]){
                pivot = i + 1;
                break;
            }
        }

        int left = 0, right = m - 1;
        while(left <= right){
            int middle = (left + right) / 2;
            int real_middle = (pivot + middle) % m;
            if(nums[real_middle] == target)
                return true;
            else if(nums[real_middle] < target)
                left = middle + 1;
            else
                right = middle - 1;
        }
        return false;
    }
};

int main() {
    Solution s;

    return 0;
}
