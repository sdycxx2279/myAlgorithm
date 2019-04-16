//
//@author Xiao Xu
//@create 2019-04-14 15:32
//Clone Graph
//图的复制，简单的dfs问题，注意使用map标注已有节点避免节点重复复制

#include <iostream>
#include <vector>
#include <stack>
#include <numeric>

using namespace std;

class Node {
public:
    int val;
    vector<Node*> neighbors;

    Node() {}

    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};

class Solution {
public:
    int candy(vector<int>& ratings) {
        Node* cloneGraph(Node* node) {
            //if(node == nullptr)
            //  return nullptr;

            if(m.find(node) != m.end())
                return m[node];
            //cout<<node->val<<endl;
            Node* clone = new Node();
            clone->val = node->val;
            m[node] = clone;

            for(Node* neighbor : node->neighbors){
                clone->neighbors.push_back(cloneGraph(neighbor));
                //cout<<neighbor->val<<" ";
            }
            return clone;
        }
    }
};

int main() {
    Solution s;

    return 0;
}
