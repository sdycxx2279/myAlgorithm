//
//@author Xiao Xu
//@create 2018-05-18 10:57
//Remove Duplicates from Sorted Array
//
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums){
        if(nums.size() == 0)
            return 0;
        int length,last;
        length = 1;
        last = 0;
        if(nums.size() == 0)
            return 0;
        for(int i = 1; i < nums.size(); i++){
            if(nums[i] != nums[last]){
                nums.erase(nums.begin()+last+1, nums.begin()+i);
                last++;
                i = last;
                length++;
            }
            if(i == nums.size() - 1){
                nums.erase(nums.begin()+last+1, nums.begin()+i+1);
            }
        }
        return length;
    }
};

int main() {
    Solution s;
    vector<int> v = {0,0,0,1,1,2,3,4,4};
    cout<<s.removeDuplicates(v);
    return 0;
}

//使用erase时间消耗太多
//for (std::vector<int>::iterator iter = nums.begin(); iter < nums.end(); ++iter)
//{
//if (iter != nums.begin())
//{
//if (*pos != *iter)
//{
//*(pos+1) = *iter;
//pos++;
//length++;
//}
//}
//}