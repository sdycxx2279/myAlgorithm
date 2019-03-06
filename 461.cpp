//
//@author Xiao Xu
//@create 2019-02-26 21:10
//Hamming Distance
//
//

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int hammingDistance(int x, int y) {
        int distance = 0;
        while(x > 0 || y > 0){
            if(x % 2 != y % 2)
                distance++;
            if(x != 0)
                x >>= 1;
            if(y != 0)
                y >>= 1;
        }

        return distance;
    }
};

int main(){
    Solution s;

    return 0;
}