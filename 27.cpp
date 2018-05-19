//
//@author Xiao Xu
//@create 2018-05-19 16:43
//Remove Element
// leetcode只会检测前返回长度以内的数组内容，超出部分视为越界不再管理
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int i = 0;
        for (int n : nums)
            if (n != val)
                nums[i++] = n;
        return i;
    }
};

int main() {
    Solution s;
    vector<int> v = {3,2,2,3};
    cout<<s.removeElement(v,2);
    return 0;
}
