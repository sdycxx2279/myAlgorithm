//
//@author Xiao Xu
//@create 2018-10-19 15:29
//Summary Ranges
//
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> result;
        if(!nums.size())
            return result;
        string temp = numToString(nums[0]);
        bool conti = false;

        for(int i = 1; i < nums.size(); i++){
            if(nums[i] == nums[i - 1] + 1){
                conti = true;
            }else{
                if(conti){
                    temp += ("->" + numToString(nums[i - 1]));
                    conti = false;
                }
                result.push_back(temp);
                temp = numToString(nums[i]);
            }
        }

        if(conti){
            temp += ("->" + numToString(nums[nums.size() - 1]));
        }
        result.push_back(temp);
        return result;
    }

    string numToString(int num){
        if(!num)
            return "0";
        else if(num == INT_MIN){
            return  "-2147483648";
        }
        bool posi = true;
        if(num < 0){
            posi = false;
            num = -num;
        }
        string temp = "";
        while(num){
            char c = num % 10 + '0';
            temp = c + temp;
            num /= 10;
        }

        return posi ? temp : "-" + temp;
    }
};

int main() {
    Solution s;

    return 0;
}
