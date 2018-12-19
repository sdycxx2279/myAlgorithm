//
//@author Xiao Xu
//@create 2018-12-19 21:10
//Lexicographical Numbers
//按字典排序，学习自讨论区，找规律题目
//

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<int> lexicalOrder(int n) {
        vector<int> res(n, 0);
        int temp = 1;
        for(int i = 0; i < n; i++){
            res[i] = temp;
            if(temp * 10 <= n)
                temp *= 10;
            else if(temp % 10 != 9 && temp + 1 <= n)
                temp++;
            else{
                while((temp / 10) % 10 == 9)
                    temp /= 10;
                temp = temp / 10 + 1;
            }
        }

        return res;
    }
};

int main(){
    Solution s;

    return 0;
}