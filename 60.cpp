//
//@author Xiao Xu
//@create 2018-08-30 22:22
//Permutation Sequence
//算出每位应该是几更快
//

#include <iostream>


using namespace std;

class Solution {
public:
    string getPermutation(int n, int k) {
        int num = 0;
        string s = "";
        for(int i = 1; i <= n; i++){
            s += ('0' + i);
        }

        return getKPermutation(s, k, &num, 0);
    }

    string getKPermutation(string s, int k, int *num, int begin){
        if(begin == s.size()){
            (*num)++;
            return (*num) == k ? s : "";
        }
        for(int i = begin; i < s.size(); i++){
            swap(s[begin], s[i]);
            string temp_str = getKPermutation(s, k, num, begin+1);
            if(temp_str != "")
                return temp_str;
        }
        return "";
    }
};

int main() {
    Solution s;

    return 0;
}
