//
//@author Xiao Xu
//@create 2018-10-16 23:12
//Kth Largest Element in an Array
//

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int left = 0, right = nums.size() - 1;

        while(left <= right){
            int pivot = quickKthSort(nums, left, right);
            /*for(int i =0; i < nums.size(); i++)
                cout<<nums[i]<<" ";
            cout<<pivot<<endl;*/
            if(pivot == k - 1)
                return nums[pivot];
            else if(pivot > k - 1)
                right = pivot - 1;
            else
                left = pivot + 1;
        }
        return -1;
    }
    int quickKthSort(vector<int>& nums, int left, int right){
        int pivot = left;
        left = left + 1;

        while(left <= right){
            while(nums[pivot] > nums[left] && nums[pivot] < nums[right] && left <= right){
                //cout<<left<<" "<<right<<endl;
                swap(nums[left++], nums[right--]);
            }

            if(nums[left] >= nums[pivot])
                left++;
            if(nums[right] <= nums[pivot])
                right--;
        }

        swap(nums[pivot], nums[right]);
        return right;
    }
};

int main(){
    Solution s;

    return 0;
}






