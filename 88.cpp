//
//@author Xiao Xu
//@create 2018-09-06 22:36
//Merge Sorted Array
//
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        n--;
        m--;
        while(m >= 0 && n >= 0){
            if(nums1[m] > nums2[n]){
                nums1[m+n+1] = nums1[m--];
            }else{
                nums1[m+n+1] = nums2[n--];
            }
        }

        while(n >= 0){
            nums1[n] = nums2[n--];
        }
    }
};

int main() {
    Solution s;

    return 0;
}
