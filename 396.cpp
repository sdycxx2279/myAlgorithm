//
//@author Xiao Xu
//@create 2018-12-25 21:10
//Rotate Function
//学习自讨论区，数学原理
//计算数组和可以使用accumulate，计算每个的和即可，没必要维护过长的数组

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int maxRotateFunction(vector<int>& A) {
        long sum = 0, f0 = 0;
        vector<long> diff(A.size(), 0);
        for(int i = 0; i < A.size(); i++){
            sum += A[i];
            diff[i] = A[i] * A.size();
            f0 += i * A[i];
        }

        long max_diff = 0;
        for(int i = A.size() - 1; i > 0; i--){
            diff[i] = sum - diff[i];
            diff[i] = i == A.size() - 1 ? diff[i] : diff[i] + diff[i + 1];
            max_diff = max(max_diff, diff[i]);
        }

        return f0 + max_diff;
    }
};

int main(){
    Solution s;

    return 0;
}