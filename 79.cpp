//
//@author Xiao Xu
//@create 2018-09-04 22:27
//Word Search
//DFS算法，将board与word作为类的私有变量会节省大量空间，使用原生的board标识是否遍历过，在结束后复原可以节省大量新建数组的时间
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        if(!word.size())
            return true;
        vector<vector<bool>> matrix(board.size(), vector<bool>(board[0].size(), false));
        for(int i = 0; i < board.size(); i++){
            for(int j = 0; j < board[i].size(); j++){
                if(getExist(board, matrix, word, i, j, 0))
                    return true;
                cout<<endl;
            }
        }
        return false;
    }

    bool getExist(vector<vector<char>>& board, vector<vector<bool>> matrix, string word, int i, int j, int num){
        if(matrix[i][j] || word[num++] != board[i][j])
            return false;
        matrix[i][j] = true;
        if(num == word.size())
            return true;
        if(i > 0 && getExist(board, matrix, word, i-1, j, num))
            return true;
        if(i < board.size()-1 && getExist(board, matrix, word, i+1, j, num))
            return true;
        if(j > 0 && getExist(board, matrix, word, i, j-1, num))
            return true;
        return j < board[0].size() - 1 && getExist(board, matrix, word, i, j + 1, num);
    }
};

int main() {
    Solution s;

    return 0;
}
