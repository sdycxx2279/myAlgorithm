//
//@author Xiao Xu
//@create 2018-10-11 22:20
//Count Primes
//没有仔细读题，理解为<=n，应为< n
//
//

#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

class Solution {
public:
    int countPrimes(int n) {
        vector<int> nums(n, 0);
        double sqrt_n = sqrt(n);
        int result = 0;
        for(int i = 2;  i < sqrt_n; i++){
            while(i < n && nums[i] == 1)
                i++;
            for(int j = 2; i * j < n; j++){
                nums[i * j] = 1;
            }
//            for(int j=i*i;j<n;j+=i)
//                flag[j]=true;
        }

        for(int i = 2; i < n; i++){
            if(!nums[i])
                result++;
        }

        return result;
    }
};

int main() {
    Solution s;

    return 0;
}
