#include "../header.h"
using namespace std;

class Solution {
public:
    vector< vector<int> > combine(int n, int k) {
        if (n<=0 || k<=0 || n<k) return {};
        vector<int> cur;
        vector< vector<int> > ans;
        dfs(n, k, cur, ans, 1);
        return ans;
    }
private:
    void dfs(int n, int k, vector<int>& cur, vector< vector<int> >& ans, int start) {
        if (cur.size() == k) {
            ans.push_back(cur);
            return;
        }
        for (int i = start; i<=n; ++i) {
            cur.push_back(i);
            dfs(n, k, cur, ans, i+1);
            cur.pop_back();
        }
        return;        
    }
};

int main() {
    Solution s;
    vector< vector<int> > ans;
    ans = s.combine(4, 2);
    for (int i=0; i<ans.size(); ++i) {
        for (int j=0; j<ans[i].size(); ++j) {
            cout << ans[i][j] << ' ';
        }
        cout << '\n';
    }
}