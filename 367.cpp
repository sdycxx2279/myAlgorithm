//
//@author Xiao Xu
//@create 2018-12-05 21:10
//Valid Perfect Square
//避免溢出

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    bool isPerfectSquare(int num) {
        int left = 1, right = num;
        while(left <= right){
            //避免溢出
            int mid = left + (right - left) / 2;
            //cout<<left<<" "<<right<<endl;
            //避免溢出
            if(num / mid == mid && !(num % mid))
                return true;
            else if(num / mid < mid)
                right = mid - 1;
            else
                left = mid + 1;
        }
        return false;
    }
};

int main(){
    Solution s;

    return 0;
}