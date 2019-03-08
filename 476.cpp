//
//@author Xiao Xu
//@create 2019-03-08 11:10
// Number Complement
//
//

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int findComplement(int num) {
        int res = 0, order = 1;
        while(num > 0){
            //cout<<num<<" "<<order<<" "<<(num&1)<<endl;
            if((num & 1) == 0){
                res += order;
            }
            order <<= 1;
            num >>= 1;
        }

        return res;
    }
};

int main(){
    Solution s;

    return 0;
}