//
//@author Xiao Xu
//@create 2018-05-02 17:36
//Container With Most Water
//
#include<iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int max_area = 0, temp_area = 0, i = 0, j =  height.size()-1;
        while(i < j){
            int h = height[i] > height[j] ? height[j] : height[i];
            temp_area = h * (j - i);
            max_area = max_area > temp_area ? max_area : temp_area;
            while(height[i] <= h && i < j)
                i++;
            while(height[j] <= h && i < j)
                j--;
        }
        return max_area;
    }
};

int main(){
    Solution s;
    vector<int> v;
    v.push_back(1);
    v.push_back(2);
//    v.push_back(1);
    cout<<s.maxArea(v);
    return 0;
}
