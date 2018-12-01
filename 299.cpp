//
//@author Xiao Xu
//@create 2018-11-18 14:03
//Bulls and Cows
//
//

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    string getHint(string secret, string guess) {
        int m = secret.size(), b = 0, c = 0;
        string hint;
        vector<int> s(10, 0), g(10, 0);
        for(int i = 0; i < m; i++){
            if(secret[i] == guess[i])
                b++;
            else{
                s[secret[i] - '0']++;
                g[guess[i] - '0']++;
            }
        }
        for(int i = 0; i < 10; i++){
            c += min(s[i], g[i]);
        }

        hint += to_string(b);
        hint += 'A';
        hint += to_string(c);
        hint += 'B';
        return hint;
    }
};

int main() {
    Solution s;

    return 0;
}
