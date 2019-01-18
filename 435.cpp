//
//@author Xiao Xu
//@create 2019-01-14 21:10
//Non-overlapping Intervals
//
//

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};

class Solution {
public:
    int eraseOverlapIntervals(vector<Interval>& intervals) {
        sort(intervals.begin(), intervals.end(), cmp);
        int last_end = INT_MIN, res = 0;
        for(Interval interval : intervals){
            if(interval.start < last_end){
                res++;
                last_end = min(last_end, interval.end);
            }else{
                last_end = interval.end;
            }

        }

        return res;
    }

    static bool cmp(Interval &i1, Interval &i2){
        if(i1.start == i2.start)
            return i1.end > i2.end;
        return i1.start < i2.start;
    }
};

int main(){
    Solution s;

    return 0;
}