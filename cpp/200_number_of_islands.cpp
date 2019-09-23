#include "header.h"
using namespace std;

// DFS
class Solution {
public:
    int numIslands(vector< vector<char> >& grid) {
        
        
    }
};

int main() {
    Solution s;
    vector< vector<char> > grid;
    vector<char> temp = {*"1", *"1", *"1", *"1", *"0"};
    grid.push_back(temp);

    temp.clear();
    temp = {*"1", *"1", *"0", *"1", *"0"};
    grid.push_back(temp);

    temp.clear();
    temp = {*"1", *"1", *"0", *"0", *"0"};
    grid.push_back(temp);

    temp.clear();
    temp = {*"0", *"0", *"0", *"0", *"0"};
    grid.push_back(temp);

    // cout << s.numIslands(grid) << endl;
    cout << temp[0] << temp[1] << temp[2] << temp[3] << temp[4] << endl;
}