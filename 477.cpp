//
//@author Xiao Xu
//@create 2019-03-08 11:10
//Total Hamming Distance
//求多数之间汉明距离，两数间汉明距离可以使用异或后统计1得到，但这样干复杂度太高
//统计指定位上1与0的数量p与q，则在该位上汉明距离为p*q

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int totalHammingDistance(vector<int>& nums) {
        if(!nums.size())
            return 0;
        int res = 0, count0, count1;
        bool run = true;

        while(run){
            run = false;
            count0 = 0;
            count1 = 0;
            for(int i = 0; i < nums.size(); i++){
                if(nums[i] & 1)
                    count1++;
                else
                    count0++;
                nums[i] >>= 1;
                if(nums[i] > 0)
                    run = true;
            }
            //cout<<count0<<" "<<count1<<endl;
            res += count1 * count0;
        }


        return res;
    }
};

int main(){
    Solution s;

    return 0;
}