//
//@author Xiao Xu
//@create 2018-12-10 21:10
//Guess Number Higher or Lower II
//学习自讨论区，dp算法
//

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int getMoneyAmount(int n) {
        vector<vector<int>> money(n + 1, vector<int>(n + 1, 0));
        return dp(1, n, money);
    }

    int dp(int left, int right, vector<vector<int>>& money){
        if(left >= right)
            return 0;
        if(money[left][right])
            return money[left][right];
        int res = INT_MAX;
        for(int i = left; i <= right; i++){
            int temp = i + max(dp(left, i - 1, money), dp(i + 1, right, money));
            res = min(res, temp);
        }

        money[left][right] = res;
        return res;
    }
};

int main(){
    Solution s;

    return 0;
}