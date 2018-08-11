//
//@author Xiao Xu
//@create 2018-08-11 22:15
//Unique Paths
//
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int uniquePaths(int m, int n) {
        if(m < n)
            return uniquePaths(n, m);

        vector<int> cur(n, 1);

        for(int i = 1; i < m; i++){
            for(int j = 1; j < n; j++){
                cur[j] += cur[j - 1];
            }
        }

        return cur[n - 1];
    }
};

int main() {
    Solution s;

    return 0;
}
