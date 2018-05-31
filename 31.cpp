//
//@author Xiao Xu
//@create 2018-05-30 0:04
//Next Permutation
//获取全排列的下一个排列，参考https://blog.csdn.net/c18219227162/article/details/50301513
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int a;
        int size_nums = nums.size();
        if(size_nums != 1) {
            a = -1;
            for(int i = size_nums - 1; i > 0; i--){
                if(nums[i] > nums[i-1]){
                    a = i - 1;
                    break;
                }
            }
            if(a != -1){
                for(int i = size_nums - 1; i > 0; i--){
                    if(nums[i] > nums[a]){
                        int temp = nums[i];
                        nums[i] = nums[a];
                        nums[a] = temp;
                        reverse(nums, a + 1, size_nums - 1);
                        break;
                    }
                }
            }else{
                reverse(nums, 0, size_nums - 1);
            }
        }
    }
    void reverse(vector<int>& nums, int begin, int end){
        if(begin < end){
            int temp = nums[begin];
            nums[begin] = nums[end];
            nums[end] = temp;
            reverse(nums, begin+1, end-1);
        }
    }
};

int main() {
    Solution s;
    vector<int> v = {1,3,2};
    s.nextPermutation(v);
    return 0;
}
