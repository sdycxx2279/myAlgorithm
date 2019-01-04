//
//@author Xiao Xu
//@create 2019-01-04 23:02
//Queue Reconstruction by Height
//学习自讨论区，先将pair按first排序，再依次插入，每次将pair插入数组其second的位置
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<pair<int, int>> reconstructQueue(vector<pair<int, int>>& people) {
        vector<pair<int, int>> res;

        sort(people.begin(), people.end(), cmp);

        for(pair<int, int> p : people){
            res.insert(res.begin() + p.second, p);
        }

        return res;
    }

    static bool cmp(pair<int,int>a,pair<int,int>b){
        return a.first > b.first || (a.first == b.first && a.second < b.second);
    }
};

int main() {
    Solution s;

    return 0;
}
