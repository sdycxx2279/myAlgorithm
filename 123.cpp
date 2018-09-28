//
//@author Xiao Xu
//@create 2018-09-28 21:08
//Best Time to Buy and Sell Stock III
//学习讨论区，使用四个标志分别表示第一次购买，第一次出售，第二次购买，第二次出售
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int hold1 = INT_MIN, hold2 = INT_MIN, release1 = 0, release2 = 0;

        for (int price : prices) {
            release2 = max(release2, hold2 + price);
            hold2 = max(hold2, release1 - price);
            release1 = max(release1, hold1 + price);
            hold1 = max(hold1, -price);
        }

        return release2;
    }
};

int main() {
    Solution s;

    return 0;
}
