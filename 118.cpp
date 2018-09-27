//
//@author Xiao Xu
//@create 2018-09-27 21:19
// Pascal's Triangle
//

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int> > result;
        for(int i = 0; i < numRows; i++){
            vector<int> temp(i + 1, 0);
            if(i == 0){
                temp[i] = 1;
                result.push_back(temp);
                continue;
            }
            for(int j = 0; j <= i; j++){
                int a = j == 0 ? 0 : result[i - 1][j - 1];
                int b = j == i ? 0 : result[i - 1][j];
                temp[j] = a + b;
            }
            result.push_back(temp);
        }

        return result;
    }
};

int main(){
    Solution s;

    return 0;
}

