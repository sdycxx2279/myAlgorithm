//
//@author Xiao Xu
//@create 2019-01-21 21:10
//Number of Boomerangs
//效率极差
//无需求sqrt，可以节省时间
//可以循环使用一个map

#include<iostream>
#include<vector>
#include <map>
#include <cmath>

using namespace std;

class Solution {
public:
    int numberOfBoomerangs(vector<pair<int, int>>& points) {
        map<double, int> ma;
        vector<map<double, int>> m(points.size(), map<double, int>(ma));

        for(int i = 0; i < points.size(); i++){
            for(int j = i + 1; j < points.size(); j++){
                double temp = sqrt(pow(points[i].first - points[j].first, 2) + pow(points[i].second - points[j].second, 2));
                m[i][temp]++;
                m[j][temp]++;
                //cout<<i<<" "<<j<<endl;
            }
        }

        map<double, int>::iterator iter;
        int res = 0;

        for(map<double, int> _map : m){
            iter = _map.begin();

            while(iter != _map.end()) {
                if(iter->second > 1){
                    res += (iter->second * (iter->second - 1));
                }
                iter++;
            }
        }

        return res;
    }
};

/*
 * map遍历
 * for(auto& kv:dmap) {
 *   int& many = kv.second;
 *   res+=many*(many-1);
 *   }
 */

int main(){
    Solution s;

    return 0;
}