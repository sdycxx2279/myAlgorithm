//
//@author Xiao Xu
//@create 2019-02-26 21:10
//Circular Array Loop
//双指针，一快一慢，题目描述即不清晰，应该是在数组中找一个圈，长度大于1，不能有反复，即1-3-2-4-1不对，若从头开始会有一个非题目定义圆的圈但从中间开始有圆也对
//vector size为unsigned int,与负数进行计算会出错

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    bool circularArrayLoop(vector<int>& nums) {
        if(nums.size() < 2)
            return false;
        for(int k = 0; k < nums.size(); k++){
            if(nums[k] == 0)
                continue;
            int i = k, j = k;
            bool first = true;
            while(i != j || first){
                i = step(i, 1, nums);
                j = step(j, 2, nums);
                //cout<<i<<" "<<j<<endl;
                if(i == j)
                    break;
                first = false;
            }

            int next = step(i, 1, nums);

            if(next == i)
                continue;
            bool pos = nums[i] > 0, end = true;
            while(next != i){
                if((nums[next] > 0 && !pos) || (nums[next] < 0 && pos)){
                    end = false;
                    break;
                }
                next = step(next, 1, nums);
            }
            if(end)
                return true;
        }

        return false;
    }

    int step(int a, int times, vector<int>& nums){
        for(int i = 0; i < times; i++){
            int x = nums.size();
            a = (a + nums[a]) % x;
            a = a < 0 ? x + a : a;
        }

        return a;
    }
};

int main(){
    Solution s;

    return 0;
}