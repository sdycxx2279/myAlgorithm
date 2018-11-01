//
//@author Xiao Xu
//@create 2018-10-29 21:09
//Different Ways to Add Parentheses
//分治法，学习自讨论区

#include<iostream>
using namespace std;

class Solution {
public:
    vector<int> diffWaysToCompute(string input) {
        vector<int> result;
        for(int i = 0; i < input.size(); i++){
            if(input[i] == '+' || input[i] == '-' || input[i] == '*'){
                vector<int> last = diffWaysToCompute(input.substr(0, i));
                vector<int> next = diffWaysToCompute(input.substr(i + 1, input.size() - i - 1));
                for(int last_num : last){
                    for(int next_num : next){
                        if(input[i] == '+')
                            result.push_back(last_num + next_num);
                        else if(input[i] == '-')
                            result.push_back(last_num - next_num);
                        else
                            result.push_back(last_num * next_num);
                    }
                }
            }
        }

        if(!result.empty())
            return result;

        int temp = 0;
        for(int i = 0; i < input.size(); i++){
            temp = temp * 10 + (input[i] - '0');
        }
        result.push_back(temp);
        return result;
    }
};

int main(){
    Solution s;

    return 0;
}