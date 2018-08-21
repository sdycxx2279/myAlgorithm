//
//@author Xiao Xu
//@create 2018-08-21 22:45
//Triangle
//使用本来就有的triangle数组存放中间数据可以避免大量的复制操作，节省时间
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        vector<int> result(triangle.size(), 0);

        for(int i = 0; i < triangle.size(); i++){
            vector<int> temp_result = result;
            for(int j = 0; j < i+1; j++){
                if(i == 0)
                    result[0] = triangle[0][0];
                else if(j == 0)
                    result[0] = temp_result[0] + triangle[i][0];
                else if(j == i)
                    result[j] = temp_result[j-1] + triangle[i][j];
                else
                    result[j] = min(temp_result[j-1], temp_result[j]) + triangle[i][j];
            }
        }
        return get_min(result);
    }

    int get_min(vector<int> nums){
        if(nums.size() == 0)
            return 0;
        int result = nums[0];
        for(int i = 1; i < nums.size(); i++){
            result = min(result, nums[i]);
        }
        return result;
    }
};

int main() {
    Solution s;

    return 0;
}

