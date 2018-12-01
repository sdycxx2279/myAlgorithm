//
//@author Xiao Xu
//@create 2018-11-28 21:10
//Verify Preorder Serialization of a Binary Tree
//

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    bool isValidSerialization(string preorder) {
        if(!preorder.size())
            return false;
        if(preorder == "#")
            return true;
        stack<string> tree;

        for(int i = 0; i < preorder.size(); i++){
            //cout<<preorder[i];
            if(preorder[i] == '#'){
                if(tree.empty()){
                    return false;
                }else if(tree.top() == "#"){
                    while(tree.top() == "#"){
                        tree.pop();
                        tree.pop();
                        if(tree.empty() && i != preorder.size() - 1)
                            return false;
                        else if(tree.empty() && i == preorder.size() - 1)
                            return true;
                    }
                }
                tree.push("#");
            }else if(preorder[i] == ','){
                continue;
            }else{
                int temp = i;
                while(i < preorder.size() && preorder[i] != ','){
                    i++;
                }
                tree.push(preorder.substr(temp, temp - i));
            }
        }

        return tree.empty();
    }
};

int main(){
    Solution s;

    return 0;
}