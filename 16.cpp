//
//@author Xiao Xu
//@create 2018-05-08 15:33
//3Sum Closest
//注意调试后的连带反应
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int result,temp_difference,last_difference,last_result;
        int length_nums = nums.size();
        sort(nums.begin(),nums.end());
        for(int i = 0; i < length_nums - 1; i++){
            int low = i + 1, high = length_nums - 1;
            bool first = true;
            while(low < high){
                int temp = nums[i] + nums[low] + nums[high];
                if(first){
                    last_difference =  target - temp;
                    if(i == 0)
                        result = temp;
                    else
                        result = abs(result - target) < abs(last_difference) ? result : last_result;
                    first = false;
                    if(last_difference < 0){
                        high--;
                    }else if(last_difference > 0){
                        low++;
                    }else{
                        result = target;
                        break;
                    }
                }else{
                    temp_difference = target - temp;
                    if(abs(temp_difference) > abs(last_difference)){
                        result = abs(result - target) < abs(last_difference) ? result : last_result;
                    }else if(temp_difference < 0){
                        high--;
                    }else if(temp_difference > 0){
                        low++;
                    }else{
                        result = target;
                        break;
                    }
                    last_difference = temp_difference;
                }
                last_result = temp;
            }
            if(abs(result - target) > abs(last_difference))
                result = last_result;
            if(result == target)
                break;
        }
        return result;
    }
};

int main() {
    Solution s;
    vector<int> v = {-55,-24,-18,-11,-7,-3,4,5,6,9,11,23,33};
    cout<<s.threeSumClosest(v,0)<<endl;
    return 0;
}
