//
//@author Xiao Xu
//@create 2019-01-14 21:10
//
//
//

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    string originalDigits(string s) {
        vector<int> v(10, 0);
        for(char c : s){
            switch(c){
                case 'z':
                    v[0]++;
                    break;
                case 'o':
                    v[1]++;
                    break;
                case 'w':
                    v[2]++;
                    break;
                case 'h':
                    v[3]++;
                    break;
                case 'r':
                    v[4]++;
                    break;
                case 'f':
                    v[5]++;
                    break;
                case 'x':
                    v[6]++;
                    break;
                case 'v':
                    v[7]++;
                    break;
                case 'g':
                    v[8]++;
                    break;
                case 'n':
                    v[9]++;
                    break;
            }
        }

        v[3] -= v[8];
        v[4] -= (v[0] + v[3]);
        v[1] -= (v[0] + v[2] + v[4]);
        v[5] -= v[4];
        v[7] -= v[5];
        v[9] = (v[9] - v[1] - v[7]) / 2;

        string res = "";
        for(int i = 0; i < 10; i++){
            string temp = to_string(i);
            for(int j = 0; j < v[i]; j++){
                res += temp;
            }
        }

        return res;
    }
};

int main(){
    Solution s;

    return 0;
}