//
//@author Xiao Xu
//@create 2019-01-14 21:10
//Third Maximum Number
//
//

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int thirdMax(vector<int>& nums) {
        long a = INT_MIN, b = INT_MIN, c = INT_MIN, count = 0;
        bool has = false;
        for(int num : nums){
            if(num > a){
                c = b;
                b = a;
                a = num;
            }else if(num < a && num > b){
                c = b;
                b = num;
            }else if(num < b && num > c){
                c = num;
            }

            if(num == INT_MIN){
                has = true;
            }

            if(num > INT_MIN){
                count++;
            }
        }
        if(count >= 2 && has && b != INT_MIN)
            return INT_MIN;

        return c != INT_MIN ? c : a;
    }
};

int main(){
    Solution s;

    return 0;
}