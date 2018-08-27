//
//@author Xiao Xu
//@create 2018-08-23 22:40
// Maximum Product Subarray
//
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        if(nums.empty())
            return 0;
        int max_unpositive, max_unnegative, max_product;
        max_unpositive = nums[0] > 0 ? 0 : nums[0];
        max_unnegative = nums[0] < 0 ? 0 : nums[0];
        max_product = nums[0];

        for(int i = 1; i < nums.size(); i++){
            if(nums[i] == 0){
                max_unpositive = 0;
                max_unnegative = 0;
            }else if(nums[i] < 0){
                int temp = max_unpositive;
                if(max_unnegative == 0){
                    max_unpositive = nums[i];
                }else{
                    max_unpositive = max_unnegative * nums[i];
                }
                max_unnegative = temp * nums[i];
            }else{
                if(max_unnegative == 0)
                    max_unnegative = nums[i];
                else
                    max_unnegative *= nums[i];
                max_unpositive *= nums[i];
            }
            max_product = max(max_product, max_unnegative);
        }
        return max_product;
    }
};

int main() {
    Solution s;

    return 0;
}


/*优化代码
int maxProduct(vector<int>& nums) {
    int curr_min = nums[0];
    int curr_max = nums[0];
    int global_max = nums[0];
    for(int i=1;i<nums.size();i++){
        int tmp = curr_min;
        curr_min=min(curr_min*nums[i],min(nums[i],curr_max*nums[i]));
        curr_max=max(tmp*nums[i],max(nums[i],curr_max*nums[i]));
        global_max = max(global_max,curr_max);
    }

    return (global_max);
}
 int maxProduct(vector<int>& nums)
    {

        if(nums.size() == 0)
        {

            return 0;

        }

        int result = nums[0];

        int minA = nums[0];

        int maxA = nums[0];

        for(int i = 1; i<nums.size(); i++)
        {

            if(nums[i] < 0)
            {

                swap(minA, maxA);

            }

            maxA = max(nums[i], nums[i]*maxA);

            minA = min(nums[i], nums[i]*minA);

            result = max(result, maxA);

        }

        return result;

    }
 */