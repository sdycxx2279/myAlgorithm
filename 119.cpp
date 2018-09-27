//
//@author Xiao Xu
//@create 2018-09-27 21:19
// Pascal's Triangle II
//

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> result(rowIndex + 1, 0);

        result[0] = 1;
        for(int i = 1; i <= rowIndex; i++){
            result[i] = result[i - 1];
            for(int j = i - 1; j > 0; j--){
                result[j] = result[j] + result[j - 1];
            }
        }
        return result;
    }
};

int main(){
    Solution s;

    return 0;
}



