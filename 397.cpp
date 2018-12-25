//
//@author Xiao Xu
//@create 2018-12-25 21:10
//Integer Replacement
//使用dp算法，一开始忘记处理INT_MAX造成错误，随后使用map优化算法，提高速度
//

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int integerReplacement(int n) {
        if(n == 1 || n <= 0)
            return 0;
        else if(n == INT_MAX)
            return 32;
        else if(m[n] != 0)
            return m[n];
        else if(n % 2 == 1)
            m[n] = min(integerReplacement((n + 1) / 2), integerReplacement(n / 2)) + 2;
        else
            m[n] = integerReplacement(n / 2) + 1;

        return m[n];
    }

private:
    map<int, int> m;
};

int main(){
    Solution s;

    return 0;
}