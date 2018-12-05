//
//@author Xiao Xu
//@create 2018-12-05 21:10
//Super Pow
//(a * b)%k = (a%k)*(b%k)%k
//

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int superPow(int a, vector<int>& b) {
        return getPow(a, b, b.size() - 1);
    }

    int getPow(int a, vector<int>& b, int last){
        if(last > -1)
            return getPowNum(getPow(a, b, last - 1), 10) * getPowNum(a, b[last]) % 1337;
        else
            return 1;
    }

    int getPowNum(int a, int b){
        if(!b)
            return 1;
        int mod = a % 1337, temp = mod;
        for(int i = 1; i < b; i++){
            temp = temp * mod % 1337;
        }
        return temp;
    }
//提高a的10次幂的计算速度
//    int pow10(int x) {
//        const auto x2 = (x * x) % 1337;
//        const auto x4 = (x2 * x2) % 1337;
//        const auto x8 = (x4 * x4) % 1337;
//        return (x2 * x8) % 1337;
//    }
};

int main(){
    Solution s;

    return 0;
}