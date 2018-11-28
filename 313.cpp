//
//@author Xiao Xu
//@create 2018-11-21 21:10
//Super Ugly Number
//

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        vector<int> index(primes.size(), 0), res(n, INT_MAX);
        res[0] = 1;

        for(int i = 1; i < n; i++){
            for(int j = 0; j < primes.size(); j++){
                res[i] = min(res[i], res[index[j]] * primes[j]);
            }
            for(int j = 0; j < primes.size(); j++){
                if(res[i] == res[index[j]] * primes[j])
                    index[j]++;
            }
        }
        return res[n - 1];
    }
};

int main(){
    Solution s;

    return 0;
}