//
//@author Xiao Xu
//@create 2018-12-01 11:59
//Flatten Nested List Iterator
//
//

#include <iostream>
#include <vector>

using namespace std;

/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */
//随意定义，避免ide报错
class NestedInteger{
public:
    bool isInteger(){
        return true;
    }

    int getInteger(){
        return 1;
    }

    vector<NestedInteger> &getList(){
        return (vector<NestedInteger> &) NULL;
    }
};

class NestedIterator {
public:
    NestedIterator(vector<NestedInteger> &nestedList) {
        getRes(nestedList);
        i = 0;
    }

    void getRes(vector<NestedInteger> &nestedList){
        for(NestedInteger nest : nestedList){
            if(nest.isInteger())
                this->res.push_back(nest.getInteger());
            else
                getRes(nest.getList());
        }
    }

    int next() {
        return res[i++];
    }

    bool hasNext() {
        return i < res.size();
    }
private:
    vector<int> res;
    int i;
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */

int main() {

    return 0;
}
