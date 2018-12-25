//
//@author Xiao Xu
//@create 2018-12-25 21:10
//UTF-8 Validation
//没注意到UTF-8最长4位的限定条件，导致一次WA
//

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    bool validUtf8(vector<int>& data) {
        int poi = 128;
        for(int i = 0; i < data.size(); i++){
            int length = 0;
            while(data[i] & poi && poi > 0){
                poi = poi >> 1;
                length++;
            }
            poi = 128;
            if(length == 1 || length > 4)
                return false;
            else if(length == 0)
                continue;
            while(length > 1){
                if(++i >= data.size() || !(data[i] & 128) || data[i] & 64)
                    return false;
                length--;
            }
        }

        return true;
    }

    //头仅有4种可能，
//    bool validUtf8(vector<int>& data) {
//        int count=0;
//        for(int i=0; i<data.size(); i++)
//        {
//            int val = data[i];
//            if(count ==0)
//            {
//                if(val >> 5 == 0b110) count=1;
//                else if(val >> 4 == 0b1110) count=2;
//                else if(val >> 3 == 0b11110) count=3;
//                else if(val >> 7) return false;
//            }
//            else
//            {
//                if(val >> 6 != 0b10)
//                    return false;
//                count--;
//            }
//        }
//        return count==0;
//    }
};

int main(){
    Solution s;

    return 0;
}