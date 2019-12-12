#include "../header.h"
using namespace std;

class Solution {
public:
    vector< vector<int> > combinationSum(vector<int>& candidates, int target) {
        if (candidates.size() == 0) return {};
        
        vector< vector<int> > ans;
        for (int i=0; i<candidates.size(); ++i) {
            vector<int> sub(candidates.begin() + i, candidates.end());
            vector<int> cur = {candidates[i]};
            int sum = candidates[i];
            dfs(sub, target, ans, cur, sum);
        }
        return ans;
    }
private:
    void dfs(vector<int>& can, int t, vector< vector<int> >& ans, vector<int>& cur, int& sum) {
        if (sum == t) {
            ans.push_back(cur);
            return;
        }
        if (sum > t) return;
        if (can.size() == 0) return;
        for (int i=0; i<can.size(); ++i) {
            cur.push_back(can[i]);
            sum += can[i];
            vector<int> sub(can.begin() + i, can.end());
            dfs(sub, t, ans, cur, sum);
            sum -= can[i];
            cur.pop_back();
        }
        return;
    }
};

int main() {
    Solution s;
    vector<int> can = {2,3,6,7};
    vector< vector<int> > ans;
    ans = s.combinationSum(can, 7);
    for (int i=0; i<ans.size(); ++i) {
        for (int j=0; j<ans[i].size(); ++j) {
            cout << ans[i][j] << ' ';
        }
        cout << '\n';
    }
}