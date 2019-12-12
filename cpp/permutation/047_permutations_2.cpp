#include "../header.h"
using namespace std;

class Solution {
public:
    vector< vector<int> > permuteUnique(vector<int>& nums) {
        if (nums.size() <= 0) return {};
        set< vector<int> > ans;
        vector<int> cur;
        sort(nums.begin(), nums.end());
        int n = nums.size();
        dfs(nums, ans, cur, n);  // how many elements needs
        vector< vector<int> > answer;
        for (vector<int> i : ans) {
            answer.push_back(i);
        }
        return answer;
    }
private:
    void dfs(vector<int>& nums, set< vector<int> >& ans, vector<int>& cur, int n) {
        if (cur.size() == n) {
            ans.insert(cur);
            return;
        }
        if (nums.size() <= 0) return;
        for (int i=0; i<nums.size(); ++i) {
            cur.push_back(nums[i]);
            vector<int> sub = nums;
            sub.erase(sub.begin() + i);
            dfs(sub, ans, cur, n);
            cur.pop_back();
        }
        return;
    }
};

int main() {
    Solution s;
    vector<int> nums = {1,2,3};
    vector< vector<int> > ans = s.permuteUnique(nums);
    for (int i=0; i<ans.size(); ++i) {
        for (int j=0; j<ans[i].size(); ++j) {
            cout << ans[i][j] << ' ';
        }
        cout << '\n';
    }
}