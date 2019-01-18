//
//@author Xiao Xu
//@create 2019-01-14 21:10
//Pacific Atlantic Water F
//dfs
//从边缘走更快，即从下游向上游
//

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<pair<int, int>> pacificAtlantic(vector<vector<int>>& matrix) {
        vector<pair<int, int>> res;
        if(matrix.empty())
            return res;
        vector<vector<int>> m(matrix.size(), vector<int>(matrix[0].size(), 0));
        this->matrix = matrix;


        for(int i = 0; i < m.size(); i++){
            for(int j = 0; j < m[0].size(); j++){
                dfs(i, j, m, INT_MAX);
                //cout<<m[i][j]<<" ";
                if(m[i][j] == 3){
                    pair<int, int> p(i, j);
                    res.push_back(p);
                }
            }
            //cout<<endl;
        }

        return res;
    }

    int dfs(int i, int j, vector<vector<int>>& m, int last){
        if(i == -1 || j == -1)
            return 1;
        if(i == m.size() || j == m[0].size())
            return 2;
        if(last < this->matrix[i][j])
            return 0;
        if(m[i][j] != 0)
            return m[i][j];

        //cout<<i<<" "<<j<<"  ";
        int num = this->matrix[i][j];
        m[i][j] = -1;
        int a = dfs(i - 1, j, m, num), b = dfs(i + 1, j, m, num), c = dfs(i, j - 1, m, num), d = dfs(i, j + 1, m, num);
        if(a == 3 || b == 3 || c == 3 || d == 3){
            m[i][j] = 3;
            return 3;
        }
        bool pa = false, at = false;
        int res = 0;
        if(a == 2 || b == 2 || c == 2 || d == 2)
            at = true;
        if(a == 1 || b == 1 || c == 1 || d == 1)
            pa = true;
        if(at && pa)
            res = 3;
        else if(at)
            res = 2;
        else if(pa)
            res = 1;
        m[i][j] = res;
        if(res != 3 && (a == -1 || b == -1 || c == -1 || d == -1))
            m[i][j] = 0;

        return res;
    }

private:
    vector<vector<int>> matrix;
};

int main(){
    Solution s;

    return 0;
}