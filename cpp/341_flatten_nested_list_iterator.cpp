#include "header.h"
using namespace std;


// This is the interface that allows for creating nested lists.
// You should not implement it, or speculate about its implementation
// 为了compile瞎写的， leetcode过了
class NestedInteger {
  public:
    NestedInteger(int v) {}
    // Return true if this NestedInteger holds a single integer, rather than a nested list.
    bool isInteger() {return true;}

    // Return the single integer that this NestedInteger holds, if it holds a single integer
    // The result is undefined if this NestedInteger holds a nested list
    int getInteger() {return 0;}

    // Return the nested list that this NestedInteger holds, if it holds a nested list
    // The result is undefined if this NestedInteger holds a single integer
    vector<NestedInteger> getList() {
        return vector<NestedInteger>({NestedInteger(1), NestedInteger(2)});
        }
};

class NestedIterator {
public:
    int index = 0;
    vector<int> a;
    NestedIterator(vector<NestedInteger> &nestedList) {
        convert(nestedList, nestedList.size());
    }
    
    void convert(vector<NestedInteger> nestedList, int s) {
        for (int i = 0; i<s; ++i) {
            if (nestedList[i].isInteger()) {
                a.push_back(nestedList[i].getInteger());
            }
            else {
                convert(nestedList[i].getList(), nestedList[i].getList().size());
            }
        }
    }

    int next() {
        return a[index++];
    }

    bool hasNext() {
        if (index < a.size()) return true;
        return false;
    }
};

int main() {
    vector<NestedInteger> nestedList;
    // Your NestedIterator object will be instantiated and called as such:
    NestedIterator i(nestedList);
    while (i.hasNext()) cout << i.next();

}