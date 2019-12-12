#include "../header.h"
using namespace std;

//dfs
class Solution {
public:
    vector< vector<int> > permute(vector<int>& nums) {
        if (nums.size() == 0) return {};
        if (nums.size() == 1) return {nums};
        vector< vector<int> > ans;
        vector<int> cur;
        dfs(nums, cur, ans, nums.size());
        return ans;
    }

private:
    void dfs(vector<int> nums, vector<int>& cur, vector< vector<int> >& ans, int l) {
        if (cur.size() == l) {
            ans.push_back(cur);
            return;
        }
        for (int i : nums) {
            cur.push_back(i);
            auto ind = find(nums.begin(), nums.end(), i);
            nums.erase(ind);
            dfs(nums, cur, ans, l);
            cur.pop_back();
            nums.insert(ind, i);
        }
    }
};

int main() {
    Solution s;
    vector<int> nums = {1,2,3};
    cout << s.permute(nums)[0][0] << endl;
}