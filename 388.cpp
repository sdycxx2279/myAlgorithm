//
//@author Xiao Xu
//@create 2018-12-19 21:10
//Longest Absolute File Path
//
//

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int lengthLongestPath(string input) {
        int max_length = 0, i = 0, level = 0;
        vector<int> folder;

        while(i < input.size()){
            if(input[i] == '\n'){
                level = 1;
                i++;
                while(i < input.size() && input[i] == '\t'){
                    i++;
                    level++;
                }
                //cout<<1<<endl;
            }else{
                bool isFile = false;
                int length = 0;
                while(input[i] != '\n' && i < input.size()){
                    if(input[i] == '.')
                        isFile = true;
                    i++;
                    length++;
                }
                //cout<<level<<" "<<folder.size()<<endl;
                if(isFile){
                    if(level == 0)
                        max_length = max(max_length, length);
                    else
                        max_length = max(max_length, folder[level - 2] + length);
                }else if(level <= folder.size()){
                    if(folder.empty())
                        folder.push_back(length + 1);
                    else
                        folder[level - 1] = folder[level - 2] + length + 1;
                }else{
                    folder.push_back(folder[level - 2] + length + 1);
                }
                //cout<<length<<" "<<max_length<<endl;
            }
        }

        return max_length;
    }
};

int main(){
    Solution s;

    return 0;
}