#include "header.h"
using namespace std;

// cannot use number repeatly
class Solution {
public:
    vector< vector<int> > combinationSum3(int k, int n) {
        if (n<1 || k<1) return {};
        vector< vector<int> > ans;
        vector<int> cur;
        dfs(k, n, ans, cur, 0, 1);
        return ans;
    }
    
private:
    void dfs(int k, int n, vector< vector<int> >& ans, vector<int>& cur, int sum, int start) {
        if (sum==n && cur.size()==k) {
            ans.push_back(cur);
            return;
        }
        if (sum>n || cur.size()>k) return;
        for (int i=start; i<=9; ++i) {
            cur.push_back(i);
            sum += i;
            dfs(k, n, ans, cur, sum, i+1);
            cur.pop_back();
            sum -= i;
        }
        return;
    }
};

int main() {
    Solution s;
    vector< vector<int> > ans = s.combinationSum3(3,9);
    for (int i=0; i<ans.size(); ++i) {
        for (int j=0; j<ans[i].size(); ++j) {
            cout << ans[i][j] << ' ';
        }
        cout << '\n';
    }
}