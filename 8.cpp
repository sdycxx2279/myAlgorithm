//
//@author Xiao Xu
//@create 2018-03-28 9:50
//
#include<iostream>
using namespace std;

//第一次修改，忘记处理'+'
//第二次修改，对于'111a11'，应返回111而非0
class Solution {
public:
    int myAtoi(string str) {
        int start = str.find_first_not_of(" ");
        int end = str.find_last_not_of(" ");
        bool negative = false;
        int temp;
        int answer = 0;
        if(str[start] == '-'){
            negative = true;
            start++;
        }else if(str[start] == '+'){
            start++;
        }
        for(int i = start; i <= end; i++){
            if(str[i] < '0' || str[i] > '9'){
                break;
            }
            temp = str[i] - 48;
            if(answer > (INT32_MAX - temp) / 10 && !negative){
                return INT32_MAX;
            }else if(-answer < (INT32_MIN + temp) / 10 && negative){
                return INT32_MIN;
            }
            answer = answer * 10 + temp;
        }
        answer = negative ? -1 * answer:answer;
        return answer;
    }
};

int main(){
    Solution s;
    cout<<s.myAtoi("  11111111111111111111111111111111111111111");
    return 0;
}

