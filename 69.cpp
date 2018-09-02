//
//@author Xiao Xu
//@create 2018-09-02 16:04
//middle * middle < x 可能会产生溢出，利用middle < x / middle可以解决
//
//

#include <iostream>
using namespace std;

class Solution {
public:
    int mySqrt(int x) {
        if(x == 1)
            return 1;
        int left = 0, right = x, middle = (left + right) / 2;
        while(left < right){
            if(middle <= x / middle && (middle+1)  > x / (middle+1))
                return middle;
            else if(middle > x / middle){
                right = middle - 1;
            }else{
                left = middle + 1;
            }
            middle = (left + right) / 2;
        }

        return middle;
    }
};

int main() {
    Solution s;

    return 0;
}
