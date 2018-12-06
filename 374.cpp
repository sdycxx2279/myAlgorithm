//
//@author Xiao Xu
//@create 2018-12-06 22:39
//Guess Number Higher or Lower
//二分查找
//

#include <iostream>
using namespace std;

int guess(int num);

class Solution {
public:
    int guessNumber(int n) {
        int left = 1, right = n, mid = left + (right - left) / 2, g_num = guess(mid);
        while(g_num != 0){
            //cout<<mid<<" "<<g_num<<endl;
            if(g_num == -1){
                right = mid - 1;
            }else{
                left = mid + 1;
            }
            mid = left + (right - left) / 2;
            //cout<<left<<" "<<right<<endl;
            g_num = guess(mid);
        }

        return mid;
    }
};

int main() {
    Solution s;

    return 0;
}
