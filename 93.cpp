//
//@author Xiao Xu
//@create 2018-09-13 22:36
//Restore IP Addresses
//一开始忘记处理0.0.0.0等情况
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> result;
        this->ip = s;
        getIp(result, 0, 0, 0, "");

        return result;
    }

    void getIp(vector<string>& result, int poi, int last_num, int segment, string str_ip){
        if(poi == this->ip.size() && segment == 4)
            result.push_back(str_ip);
        if(poi == this->ip.size() || segment == 4)
            return ;
        if(this->ip[poi] == '0' && last_num == 0){
            str_ip += segment == 3 ? "0" : "0.";
            getIp(result, poi + 1, 0, segment + 1, str_ip);
            return ;
        }
        int now_num = last_num * 10 + (this->ip[poi] - '0');
        if(now_num >255)
            return ;
        getIp(result, poi + 1, now_num, segment, str_ip);
        string str_now = "";
        while(now_num){
            char str_num = '0' + now_num % 10;
            str_now = str_num + str_now;
            now_num /= 10;
        }
        str_ip += segment == 3 ? str_now : str_now + '.';
        getIp(result, poi + 1, 0, segment + 1, str_ip);
    }

private:
    string ip;
};

int main() {
    Solution s;

    return 0;
}
