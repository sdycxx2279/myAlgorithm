//
//@author Xiao Xu
//@create 2018-09-27 21:19
//Best Time to Buy and Sell Stock II
//

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int result = 0, buyPrice = 0;
        bool has = false;

        for(int i = 0; i < prices.size(); i++){
            if(!has && prices[i] < prices[i + 1]){
                has = true;
                buyPrice = prices[i];
            }
            //加了个else节省一半时间
            else if(has && prices[i] > prices[i + 1]){
                has = false;
                result += (prices[i] - buyPrice);
            }
        }
        if(has)
            result += (prices[prices.size() - 1] - buyPrice);

        return result;
    }
};

int main(){
    Solution s;

    return 0;
}



