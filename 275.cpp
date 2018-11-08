//
//@author Xiao Xu
//@create 2018-11-08 22:34
//H-Index II
//照搬hIndexI 算法，使用折半查找更快
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int hIndex(vector<int>& citations) {
        int h = citations.size();
        for(int i = 0; i < citations.size(); i++){
            if(citations[i] >=  h)
                return h;
            h--;
        }
        return 0;
    }
};

int main() {
    Solution s;

    return 0;
}
