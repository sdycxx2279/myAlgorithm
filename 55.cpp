//
//@author Xiao Xu
//@create 2018-08-28 22:15
//Jump Game
//nums为[0]时应返回true
//倒序查找速度更快，或者正序使用贪心算法。。每次找到当前位置所能到达的最大距离，并与总体的最大可达距离进行比较
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int m = nums.size();
        if(!m)
            return false;
        vector<bool> jump(m, false);
        jump[0] = true;

        for(int i = 0; i < m; i++){
            if(jump[i]){
                for(int j = i + 1; j <= i + nums[i] && j < m; j++){
                    jump[j] = true;
                }
                if(jump[m-1])
                    return true;
            }
        }

        return jump[m-1];
    }
};

int main() {
    Solution s;

    return 0;
}
//bool canJump(vector<int>& nums) {
//
//    int last_reachable = nums.size()-1;
//    for (int i = nums.size()-1;i>=0;i--)
//    {
//        if(last_reachable <= i + nums[i])
//            last_reachable = i;
//    }
//
//    return last_reachable == 0;
//
//
//}

//int curpos = 0;
//int i = 0;
//
//while(i <= curpos) {
//curpos = max(i + nums[i], curpos);
//
//if(curpos >= (nums.size() - 1))
//return true;
//++i;
//}
//
//return false;