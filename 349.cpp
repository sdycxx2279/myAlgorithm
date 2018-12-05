//
//@author Xiao Xu
//@create 2018-12-05 21:10
//Intersection of Two Arrays
//

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int>m;
        vector<int> result;
        for(int num : nums1)
            m[num] = 1;
        for(int num : nums2){
            if(m[num]){
                result.push_back(num);
                m[num]--;
            }
        }

        return result;
    }
};

int main(){
    Solution s;

    return 0;
}