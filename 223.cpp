//
//@author Xiao Xu
//@create 2018-10-19 15:29
//Rectangle Area
//
//

#include <iostream>
using namespace std;

class Solution {
public:
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        int result = (C - A) * (D - B) + (G - E) * (H - F);

        if((C < E && C < G) || (G < A && G < C) || (B < F && D < F) || (B > H && D > H))
            return result;
        int min_left = max(A, E), min_right = min(C, G), min_top = min(D, H), min_bottom = max(B, F);
        return result - (min_right - min_left) * (min_top - min_bottom);
    }
    //int left = max(A,E), right = max(min(C,G), left);
    //int bottom = max(B,F), top = max(min(D,H), bottom);
};

int main() {
    Solution s;

    return 0;
}
