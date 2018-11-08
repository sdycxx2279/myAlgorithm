//
//@author Xiao Xu
//@create 2018-11-08 22:34
//First Bad Version
//一开始写mid = (left + right)/2,结果溢出，改为mid = left + (right - left) / 2
//

#include <iostream>
using namespace std;

class Solution {
public:
    bool isBadVersion(int version);
    int firstBadVersion(int n) {
        int left = 1, right = n;
        while(left <= right){
            int mid = left + (right - left) / 2;
            if(isBadVersion(mid) && (mid == 1 || !isBadVersion(mid - 1)))
                return mid;
            else if(isBadVersion(mid))
                right = mid - 1;
            else
                left = mid + 1;
        }
        return left;
    }
};

int main() {
    Solution s;

    return 0;
}
