//
//@author Xiao Xu
//@create 2018-11-07 21:10
//H-Index
//

#include<iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int hIndex(vector<int>& citations) {
        sort(citations.begin(), citations.end());
        int h = citations.size();
        for(int i = 0; i < citations.size(); i++){
            if(citations[i] >=  h)
                return h;
            h--;
        }
        return 0;
    }
//空间换时间，统计引用数存为数组，例如数组位置1存放引用数为1的论文数目，引用数超过发表文章总数的都存入位置n
//从尾部遍历得到的数组，通过两个标志位得出结果
//    int hIndex(vector<int>& citations)
//    {
//        int n = citations.size();
//        vector<int> papers(citations.size()+1, 0);
//        for (auto c : citations)
//            papers[min(n,c)]++;
//        int h = n;
//        for (int s=papers[n]; h>s; s+=papers[h])
//            h--;
//        return h;
//    }
};

int main(){
    Solution s;

    return 0;
}