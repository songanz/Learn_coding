#include "header.h"
using namespace std;

class Solution {
public:
    vector< vector<int> > combinationSum2(vector<int>& candidates, int target) {
        if (candidates.size() == 0) return {};
        sort(candidates.begin(), candidates.end());
        set< vector<int> > ans;  // for uniqueness 
        for (int i=0; i<candidates.size(); ++i) {
            vector<int> sub(candidates.begin()+i+1, candidates.end());  // start from i+1 for uniqueness
            vector<int> cur = {candidates[i]};
            int sum = candidates[i];
            dfs(sub, target, ans, cur, sum);
        }
        vector< vector<int> > answer;
        for (vector<int> i : ans) {
            answer.push_back(i);
        }
        return answer;
    }
private:
    void dfs(vector<int>& can, int t, set< vector<int> >& ans, vector<int>& cur, int& sum) {
        if (sum == t) {
            ans.insert(cur);
            return;
        }
        if (sum > t) return;
        if (can.size() == 0) return;
        for (int i=0; i<can.size(); ++i) {
            cur.push_back(can[i]);
            sum += can[i];
            vector<int> sub(can.begin()+i+1, can.end());
            dfs(sub, t, ans, cur, sum);
            sum -= can[i];
            cur.pop_back();
        }
        return;
    }
};

int main() {
    Solution s;
    vector<int> can = {10,2,4,1,7,5,1,5,6,8};
    vector< vector<int> > ans;
    ans = s.combinationSum2(can, 8);
    for (int i=0; i<ans.size(); ++i) {
        for (int j=0; j<ans[i].size(); ++j) {
            cout << ans[i][j] << ' ';
        }
        cout << '\n';
    }
}