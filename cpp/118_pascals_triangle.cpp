#include "header.h"
using namespace std;

class Solution {
public:
    vector< vector<int> > generate(int numRows) {
        //corner cases
        if (numRows < 1) return {};
        vector< vector<int> > ans = {{1}};
        for (int i=1; i<numRows; ++i) {
            vector<int> next_ = next_row(ans.back());
            ans.push_back(next_);
        }
        return ans;
    }
private:
    vector<int> next_row(vector<int> p) {
        p.push_back(0);
        p.insert(p.begin(), 0);
        vector<int> res;
        for (int i=0; i<p.size()-1; ++i) {
            res.push_back(p[i] + p[i+1]);
        }
        return res;
    }
};

int main() {
    Solution s;
    cout << s.generate(5)[3][2] << endl;
}