//
//@author Xiao Xu
//@create 2018-08-21 22:46
//Best Time to Buy and Sell Stock
//
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int result = 0;
        int min_price = INT_MAX;

        for(int i = 0; i < prices.size(); i++){
            //使用min函数，在更新最小价格时多计算一部result，比较时间消耗增多
            if(min_price >= prices[i])
                min_price = prices[i];
            else
                result = max(result, prices[i] - min_price);

        }
        return  result;
    }
};

int main() {
    Solution s;

    return 0;
}
