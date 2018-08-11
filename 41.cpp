//
//@author Xiao Xu
//@create 2018-06-26 20:35
//Submission Detail
//"各归其位"：假设数组有n个数，那么最小整数一定在1~n之间
//将swap函数修改为自定义的之后效率提升1ms（进步30%。。。。）
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int length_nums = nums.size();
        for(int i = 0; i < length_nums; i++){
            if(nums[i] > 0 && nums[i] <= length_nums && nums[i] != nums[nums[i] - 1]){
                int temp = nums[i];
                nums[i] = nums[temp - 1];
                nums[temp - 1] = temp;
//                swap(nums[i], nums[nums[i] - 1]);
                i--;
            }
        }

        for(int i = 0; i < length_nums; i++){
            if(nums[i] != i + 1)
                return i + 1;
        }
        return length_nums + 1;
    }
};

int main() {
    Solution s;
    vector<int> nums = {};
    cout<<s.firstMissingPositive(nums);
    return 0;
}
