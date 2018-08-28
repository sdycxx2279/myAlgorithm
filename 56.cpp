//
//@author Xiao Xu
//@create 2018-08-28 22:15
//Merge Intervals
//自己写sort时间消耗大许多。。。
//先填入结果数组，再修改优化时间
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};

class Solution {
public:
    static int compare(Interval a, Interval b)
    {

        return a.start < b.start;

    }

    vector<Interval> merge(vector<Interval>& intervals) {
        vector<Interval> result;
        int m  = intervals.size();
        if(!m)
            return result;

        sort(intervals.begin(), intervals.end(), compare);

        for(int i = 0; i < m - 1; i++){
            if(intervals[i].end >= intervals[i+1].start){
                intervals[i+1].start = intervals[i].start;
                intervals[i+1].end = intervals[i].end < intervals[i+1].end ? intervals[i+1].end : intervals[i].end;
            }else{
                result.push_back(intervals[i]);
            }
        }

        result.push_back(intervals[m - 1]);
        return  result;
    }

//    void sort(vector<Interval>& intervals, int left, int right){
//        if(left < right){
//            int i = left;
//            int j = right;
//
//            while(i < j){
//                while(intervals[j].start >= intervals[left].start && i < j)
//                    j--;
//                while(intervals[i].start <= intervals[left].start && i < j)
//                    i++;
//                if(i < j)
//                    swap(intervals[i], intervals[j]);
//            }
//
//            swap(intervals[i], intervals[left]);
//            sort(intervals, left, i - 1);
//            sort(intervals, i + 1, right);
//        }
//    }
};

int main() {
    Solution s;

    return 0;
}
//vector<Interval> merge(vector<Interval>& intervals)
//{
//
//    vector<Interval> result;
//
//    sort(intervals.begin(), intervals.end(), compare);
//
//    for(Interval it : intervals)
//    {
//
//        if(result.empty() || (result.back()).end < it.start)
//        {
//
//            result.push_back(it);
//
//        }
//
//        else
//        {
//
//            (result.back()).end = max((result.back()).end, it.end);
//
//        }
//
//    }
//
//    return result;
//
//}