//
//@author Xiao Xu
//@create 2018-10-22 21:19
//Majority Element II
//Boyer-Moore Majority Vote algorithm

#include<iostream>
using namespace std;

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int> result;
        int length_n = nums.size(), num1, num2, count1 = 0, count2 = 0;

        for(int i = 0; i < length_n; i++){
            if(!count1 && (count2 && nums[i] != num2)){
                count1++;
                num1 = nums[i];
            }else if(nums[i] == num1){
                count1++;
            }else if(!count2){
                count2++;
                num2 = nums[i];
            }else if(nums[i] == num2){
                count2++;
            }else{
                count1--;
                count2--;
            }
        }
        count1 = 0;
        count2 = 0;

        for(int i = 0; i < length_n; i++){
            if(num1 == nums[i])
                count1++;
            else if(num2 == nums[i])
                count2++;
        }

        if(count1 > length_n / 3)
            result.push_back(num1);
        if(count2 > length_n / 3)
            result.push_back(num2);

        return result;
    }
};

int main(){
    Solution s;

    return 0;
}



