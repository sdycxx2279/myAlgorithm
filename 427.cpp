//
//@author Xiao Xu
//@create 2019-01-14 21:10
//Construct Quad Tree
//
//

#include<iostream>
#include<vector>
using namespace std;

class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;

    Node() {}

    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};

class Solution {
public:
    Node* construct(vector<vector<int>>& grid) {
        this->grid = grid;
        return build(0, grid.size() - 1, 0, grid.size() - 1);
    }

    Node* build(int top, int bottom, int left, int right){
        if(top > bottom || left > right)
            return NULL;
        bool isLeaf = true, val = this->grid[top][left];
        for(int i = top; i <= bottom; i++){
            for(int j = left; j <= right; j++){
                if(this->grid[i][j] != val){
                    isLeaf = false;
                    break;
                }
            }
        }

        if(isLeaf){
            return new Node(val, true, NULL, NULL, NULL, NULL);
        }

        int col = (left + right) / 2, row = (top + bottom) / 2;

        return new Node(false, false, build(top, row, left, col), build(top, row, col + 1, right), build(row + 1, bottom, left, col), build(row + 1, bottom, col + 1, right));
    }


private:
    vector<vector<int>> grid;
};

int main(){
    Solution s;

    return 0;
}