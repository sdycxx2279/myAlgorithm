//
//@author Xiao Xu
//@create 2019-01-18 21:10
//Find Right Interval
//学习自讨论区
//

#include<iostream>
#include<vector>
#include <map>

using namespace std;

struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};

class Solution {
public:
    vector<int> findRightInterval(vector<Interval>& intervals) {
        vector<int> res;
        map<int, int> m;

        for(int i = 0; i < intervals.size(); i++){
            m[intervals[i].start] = i;
        }

        for(Interval i : intervals){
            auto temp = m.lower_bound(i.end);
            if(temp == m.end())
                res.push_back(-1);
            else
                res.push_back(temp->second);
        }
        return res;
    }
};

int main(){
    Solution s;

    return 0;
}