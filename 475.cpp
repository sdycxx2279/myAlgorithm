//
//@author Xiao Xu
//@create 2019-03-04 21:10
//Heaters
//寻找每个house与其左侧最近热点的距离与右侧最近热点的距离，再取二者最小值
//

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        if(!houses.size() || !heaters.size())
            return 0;
        sort(houses.begin(), houses.end());
        sort(heaters.begin(), heaters.end());

        vector<int> radius(houses.size(), INT_MAX);

        int j = 0;
        for(int i = 0; i < houses.size(); i++){
            while(j < heaters.size() && houses[i] > heaters[j]){
                j++;
            }
            if(j >= heaters.size())
                break;
            radius[i] = heaters[j] - houses[i];
        }

        j = heaters.size() - 1;
        for(int i = houses.size() - 1; i >= 0; i--){
            while(j >= 0 && houses[i] < heaters[j]){
                j--;
            }
            if(j < 0)
                break;
            radius[i] = min(houses[i] - heaters[j], radius[i]);
        }
        int res = 0;
        for(int r : radius){
            res = max(res, r);
        }

        return res;
    }
};

int main(){
    Solution s;

    return 0;
}