//
//@author Xiao Xu
//@create 2018-12-26 21:10
//Binary Watch
//
//

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<string> readBinaryWatch(int num) {
        vector<string> res;
        getRes(res, num, 0, 0, 1, 1);
        return res;
    }

    void getRes(vector<string> &res, int num, int hour, int minutes, int h_led, int m_led){
        if(hour > 11 || minutes > 59){
            return ;
        }else if(!num){
            res.push_back(getTime(hour, minutes));
        }else if(h_led > 8 && m_led > 32){
            return ;
        }else if(h_led <= 8){
            getRes(res, num - 1, hour + h_led, minutes, h_led << 1, m_led);
            getRes(res, num, hour, minutes, h_led << 1, m_led);
        }else{
            getRes(res, num - 1, hour, minutes + m_led, h_led, m_led << 1);
            getRes(res, num, hour, minutes, h_led, m_led << 1);
        }
    }


    string getTime(int hour, int minutes){
        string time = to_string(hour);
        time += ":";
        if(minutes < 10)
            time += "0";
        time += to_string(minutes);

        return time;
    }
};

int main(){
    Solution s;

    return 0;
}