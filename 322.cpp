//
//@author Xiao Xu
//@create 2018-11-26 12:08
//Coin Change
//
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> res(amount + 1, -1);
        res[0] = 0;
        for(int i = 1; i <= amount; i++){
            for(int j = 0; j < coins.size(); j++){
                if(i - coins[j] >= 0 && res[i - coins[j]] != -1){
                    res[i] = res[i] == -1 ? res[i - coins[j]] + 1 : min(res[i], res[i - coins[j]] + 1);
                }
            }
            //cout<<res[i]<<" ";
        }
        return res[amount];
    }
};

int main() {
    Solution s;

    return 0;
}
