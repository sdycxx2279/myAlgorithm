//
//@author Xiao Xu
//@create 2018-11-18 13:59
//Find the Duplicate Number
//折半查找，每次寻找计算低于中位数的数与高于中位数的数量哪个更多
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int left = 1, right = nums.size() - 1;
        while(left < right){
            int mid = (left + right) / 2, count = 0;
            for(int num : nums){
                if(num <= mid)
                    count++;
            }
            if(count <= mid)
                left = mid + 1;
            else
                right = mid;
        }
        return left;
    }
};

int main() {
    Solution s;

    return 0;
}
