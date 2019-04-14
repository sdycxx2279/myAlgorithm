//
//@author Xiao Xu
//@create 2019-04-14 15:32
//candy
//贪心算法，左一遍右一遍

#include <iostream>
#include <vector>
#include <stack>
#include <numeric>

using namespace std;

class Solution {
public:
    int candy(vector<int>& ratings) {
        vector<int> candys(ratings.size(), 1);
        for(int i = 1; i < ratings.size(); i++){
            if(ratings[i] > ratings[i - 1]){
                candys[i] = candys[i - 1] + 1;
            }
        }

        for(int i = int(ratings.size()) - 2; i >= 0; i--){
            if(ratings[i] > ratings[i + 1]){
                candys[i] = max(candys[i + 1] + 1, candys[i]);
            }
        }

        return accumulate(candys.begin(), candys.end(), 0);
    }
};

int main() {
    Solution s;

    return 0;
}
