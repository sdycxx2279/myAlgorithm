//
//@author Xiao Xu
//@create 2018-06-27 9:46
//
//
//

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        int i = 0, length = height.size();
        while(i < length && height[i] == 0 ){
            i++;
        }
        return trapOne(height, i);
    }

    int trapOne(vector<int>& height,int i){
        int begin, j, trap_size = 0, length = height.size();
        stack<int> elevation;
        if(i >= length - 1)
            return 0;
        begin = height[i];
        for(j = i + 1; j < length; j++){
            while(j < length - 1 && height[j] == height[j+1])
                j++;
            if(j == length - 1)
                break;
            begin = height[j];
            if(height[j] < begin){
                elevation.push(height[j]);
            }else{
                int low = begin > height[j] ? height[j] : begin;
                while(!elevation.empty()){
                    int now = elevation.top();
                    elevation.pop();
                    trap_size += (low - now);
                }
            }
        }
        if(elevation.empty() || j == i + 1)
            return trap_size;
        else
            return trapOne(height, begin);
    }
};

int main() {
    Solution s;
    vector<int> nums = {0,1,0,2,1,0,1,3,2,1,2,1};
    cout<<s.trap(nums);
    return 0;
}
