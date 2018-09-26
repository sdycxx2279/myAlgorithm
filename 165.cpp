//
//@author Xiao Xu
//@create 2018-09-26 20:27
//Compare Version Numbers
//
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int compareVersion(string version1, string version2) {
        int i = 0, j = 0, temp1 = 0, temp2 = 0;
        while(i < version1.size() && j < version2.size()){
            while(version1[i] != '.' && i < version1.size())
                temp1 = temp1 * 10 + (version1[i++] - '0');
            while(version2[j] != '.' && j < version2.size())
                temp2 = temp2 * 10 + (version2[j++] - '0');
            if(temp1 < temp2)
                return -1;
            else if(temp1 > temp2)
                return 1;
            temp1 = temp2 = 0;
            i++;
            j++;
        }

        if(i < version1.size() && judge(version1, i))
            return 1;
        else if(j < version2.size() && judge(version2, j))
            return -1;
        else
            return 0;
    }

    bool judge(string str, int begin){
        for(int i = begin; i < str.size(); i++){
            if(str[i] != '0' && str[i] != '.')
                return true;
        }
        return false;
    }
};

int main() {
    Solution s;

    return 0;
}




