//
//@author Xiao Xu
//@create 2018-06-27 9:46
//Trapping Rain Water
//双指针,每一次循环，left一次性走到本次指定位置，right一次性走到本次指定位置，结束本次循环
//忘记处理[]
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        if(height.size() == 0)
            return 0;

        int left = 1;
        int right = height.size() - 2;
        int result = 0;

        int max_left = height[0];
        int max_right = height[right+1];

        while(left <= right){
            if(max_left <= max_right){
                if(max_left <= height[left]){
                    max_left = height[left];
                }else{
                    result += (max_left - height[left]);
                }
                left++;
            }else{
                if(max_right <= height[right]){
                    max_right = height[right];
                }else{
                    result += (max_right - height[right]);
                }
                right--;
            }
        }

        return result;
    }
};

int main() {
    Solution s;
    vector<int> nums = {0,1,0,2,1,0,1,3,2,1,2,1};
    cout<<s.trap(nums);
    return 0;
}

/*
 * 优秀代码思路
 *  只有先下降后上升才能储水，所以要先找到第一个下降点"drop"，即（非严格）单调上升后首次下降的位置；
 *    之后，每次都记录遇到"drop"之后最高的地方，有两种可能：
 *      1 之后有比"drop"更高或持平的地方记为"raise"，
 *      2 已知搜索到结束，之后都没有更高或持平的地方，那么找到记录的最高的地方记为raise；
 *      这时水位高度为min(drop,raise)；计算其间的水量后，在raise之后寻找新的上升点"drop"
 *      持续这一过程，直到找不到新的drop点了。
 *

 *
 */