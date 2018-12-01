//
//@author Xiao Xu
//@create 2018-11-26 12:09
//Wiggle Sort II
//排序后双指针交替赋值
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        vector<int> sorted(nums);
        sort(sorted.begin(), sorted.end());

        for(int i = nums.size() - 1, j = 0, k = i / 2 + 1; i >= 0; i--){
            nums[i] = sorted[i & 1 ? k++ : j++];
        }
    }
};

int main() {
    Solution s;

    return 0;
}
