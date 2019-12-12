#include "../header.h"
using namespace std;

class Solution {
public:
    vector< vector<int> > subsetsWithDup(vector<int>& nums) {
        if (nums.size() == 0) return {};
        int n = nums.size();
        sort(nums.begin(),nums.end());
        set< vector<int> > ans = {{}};  // for uniqueness
        vector<int> cur;
        // i is how many number in the subsets
        for (int i=1; i<=n; ++i) {
            dfs(nums, i, ans, cur, 0);
        }
        vector<vector<int>> answer;
        for (vector<int> i : ans) {
            answer.push_back(i);
        }
        return answer;
    }
private:
    void dfs(vector<int>& nums, int k, set< vector<int> >& ans, vector<int> cur, int start) {
        if (cur.size() == k) {
            ans.insert(cur);
            return;
        }
        if (cur.size() > k) return;
        if (nums.size() == 0) return;
        if (start >= nums.size()) return;
        for (int i=start; i<nums.size(); ++i) {
            cur.push_back(nums[i]);
            dfs(nums, k, ans, cur, i+1);
            cur.pop_back();
        }
        return;
    }
};

int main() {
    Solution s;
    vector<int> nums = {1,3,5,2,6,7};
    vector< vector<int> > ans = s.subsetsWithDup(nums);
    for (int i=0; i<ans.size(); ++i) {
        for (int j=0; j<ans[i].size(); ++j) {
            cout << ans[i][j] << ' ';
        }
        cout << '\n';
    }
}