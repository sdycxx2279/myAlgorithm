//
//@author Xiao Xu
//@create 2018-09-14 15:33
//Gas Station
//
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int m = gas.size();
        for(int i = 0; i < m; i++){
            int gas_remain = 0;
            for(int j = 0; j < m; j++){
                int n = (j + i) % m;
                gas_remain += (gas[n] - cost[n]);
                if(gas_remain < 0)
                    break;
            }
            if(gas_remain >= 0)
                return i;
        }
        return -1;
    }
};

int main() {
    Solution s;

    return 0;
}

//很有趣的思路，如果能走通，则最后gas剩余量必>=0, gas剩余量最小（下一站点必为正）点的下一节点即为所求
//int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
//    int min = INT_MAX;
//    int min_index = 0;
//    int gap=0;
//    for( int i=0; i<gas.size(); ++i){
//        gap += gas[i];
//        gap -= cost[i];
//        if( gap < min){
//            min = gap;
//            min_index = i;
//        }
//    }
//    if( gap < 0 ){
//        return -1;
//    }
//    int greedy = (min_index+1) % gas.size();
//
//    return greedy;
//}
//