//
//@author Xiao Xu
//@create 2018-09-04 22:26
//Sort Colors
//使用4个指针遍历会更快，两个表示当前遍历到的位置，两个表示1和2的实际位置
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int left = 0, right = nums.size() - 1;
        int mid = left + 1;
        if(right == -1)
            return ;
        while(left < right){
            if(nums[left] == 0)
                left++;
            else if(nums[right] == 2)
                right--;
            else if(nums[left] == 1 && nums[right] == 0){
                swap(nums[left++], nums[right]);
            }else if(nums[left] == 1 && nums[right] == 1){
                mid = mid > left ? mid : left + 1;
                while(mid < right && nums[mid] == 1)
                    mid++;
                if(mid < right){
                    if(!nums[mid])
                        swap(nums[left++], nums[mid++]);
                    else
                        swap(nums[mid++], nums[right--]);
                }else
                    break;
            }else if(nums[left] == 2 && nums[right] == 0){
                swap(nums[left++], nums[right--]);
            }else{
                swap(nums[left], nums[right--]);
            }
        }
    }
};

int main() {
    Solution s;

    return 0;
}
