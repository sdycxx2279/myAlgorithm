//
//@author Xiao Xu
//@create 2018-12-06 22:39
//Find K Pairs with Smallest Sums
//使用大顶堆更快， <pair<int,pair<int,int>> 两数和，nums1的index，nums2的index
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<pair<int, int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<int> index1(nums1.size(), 0);
        vector<pair<int, int>> res;
        if(nums1.empty() || nums2.empty() || k <= 0)
            return res;
        int last_j = 0;
        for(int i = 0; i < k; i++){
            int min_num = INT_MAX, min_index = -1;
            for(int j = last_j; j < nums1.size(); j++){
                if(!index1[j]){
                    if(nums1[j] + nums2[0] < min_num){
                        min_index = j;
                        min_num = nums1[j] + nums2[0];
                    }
                    break;
                }else if(index1[j] == nums2.size()){
                    last_j++;
                    continue;
                }else{
                    if(nums1[j] + nums2[index1[j]] < min_num){
                        min_index = j;
                        min_num = nums1[j] + nums2[index1[j]];
                    }
                }
            }

            if(min_index == -1)
                break;
            pair<int, int> p(nums1[min_index], nums2[index1[min_index]++]);
            res.push_back(p);
        }

        return res;
};

int main() {
    Solution s;

    return 0;
}
