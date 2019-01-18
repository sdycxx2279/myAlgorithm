//
//@author Xiao Xu
//@create 2019-01-14 21:10
//
//
//

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int countBattleships(vector<vector<char>>& board) {
        int res = 0;

        for(int i = 0; i < board.size(); i++){
            for(int j = 0; j < board[i].size(); j++){
                if(board[i][j] == 'X'){
                    if((i > 0 && board[i - 1][j] == 'X') || (j > 0 && board[i][j - 1] == 'X'))
                        continue;
                    res++;
                    //cout<<i<<" "<<j<<endl;
                }
            }
        }

        return res;
    }
};

int main(){
    Solution s;

    return 0;
}