//
//@author Xiao Xu
//@create 2018-09-08 12:37
//Gray Code
//
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:

    vector<int> grayCode(int n) {
        vector<int> result;
        if (n > 0) {
            grayCodeHelper(n, result);
        } else {
            result.push_back(0);
        }
        return result;
    }

    void grayCodeHelper(int n, vector<int>& res) {
        if (n == 1) {
            res.push_back(0);
            res.push_back(1);
            return;
        }

        grayCodeHelper(n-1, res);
        int size = res.size()-1;

        for (int i = size; i >= 0; --i) {
            int num = res[i] | (1<<(n-1));
            res.push_back(num);
        }
    }

    //优化
//    vector<int> grayCode(int n) {
//        if(n==0) return {0};
//        vector<int> res;
//        res.push_back(0);
//        res.push_back(1);
//        for(int i=1;i<n;i++) {
//            int len=res.size();
//            for(int j=len-1;j>=0;j--) {
//                res.push_back(res[j]+(1<<i));
//            }
//        }
//        return res;
//    }

    //错误代码，未注意必须从0开始条件
//    vector<int> grayCode(int n) {
//        bool isZero = true;
//        vector<int> result(1 << n, 0);
//        for(int i = 0; i < n; i++){
//            int margin = 1 << (n - i - 1);
//            int num = 1 << i;
//            for(int j = 0; j < num; j++){
//                int dad = margin * 2 * j;
//                int temp = result[dad];
//                if(isZero){
//                    result[dad] = temp * 2 + 0;
//                    result[dad + margin] = temp * 2 + 1;
//                }else{
//                    result[dad] = temp * 2 + 1;
//                    result[dad + margin] = temp * 2 + 0;
//                }
//                isZero = !isZero;
//            }
//        }
//
//        return result;
//    }
};

int main() {
    Solution s;

    return 0;
}
