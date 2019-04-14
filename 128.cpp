//
//@author Xiao Xu
//@create 2019-04-13 16:10
//Longest Consecutive Sequence
//求未排序数组中数字能组成的最长连续序列的长度，不考虑连续数字
//算法要求O（n），但O（nlogn）算法打败了95%。。。可能数据量的问题吧
//

#include<iostream>
#include<vector>
#include <map>
using namespace std;

class Solution {
public:
    //我的O(nlogn)算法
    int longestConsecutive(vector<int>& nums) {
        if(nums.size() < 2)
            return nums.size();
        map<int, int> m;
        for(int num : nums){
            m[num] = 1;
        }
        int res = 1;
        auto last = m.begin();
        m.begin()->second = 1;
        for(auto iter = m.begin(); iter != m.end(); iter++){
            //cout<<iter->first<<endl;
            if(iter->first == last->first + 1){
                iter->second = last->second + 1;
                res = max(iter->second, res);
            }
            last = iter;
        }

        return res;
    }
/*
 * O(n)算法，使用unordered_map（O(1)）
    for (int num : num_set) {
        if (num_set.find(num - 1) == num_set.end()) {
            int currentNum = num;
            int currentStreak = 1;

            while (num_set.find(currentNum+1) != num_set.end()) {
                currentNum += 1;
                currentStreak += 1;
            }

            longestStreak = max(longestStreak, currentStreak);
        }
    }
*/

};

int main(){
    Solution s;

    return 0;
}