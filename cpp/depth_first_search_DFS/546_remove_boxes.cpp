#include "../header.h"
using namespace std;

// 三维DP + dfs
// 很难，看花花
class Solution {
public:
    int removeBoxes(vector<int>& boxes) {
        len_ = vector<int>(boxes.size());
        for (int i=1; i<boxes.size(); i++) {
            if (boxes[i] == boxes[i-1]) len_[i] = len_[i-1] + 1;
        }
        return dfs(boxes, 0, boxes.size()-1, 0);
    }

private:
    unordered_map<int, int> m_;
    vector<int> len_;
    // l: left position; r: right position; k: r+1到n之间有几个和r相同颜色的方块
    int dfs(const vector<int>& boxes, int l, int r, int k) {
        if (l > r) return 0;
        k += len_[r];
        r -= len_[r];
        int key = (l*100 + r)*100 + k;
        // if already calculated
        auto it = m_.find(key);
        if (it != m_.end()) return it->second;

        // DP
        int& ans = m_[key];
        ans = dfs(boxes, l, r-1, 0) + (k+1)*(k+1);
        for (int i=l; i<r; i++) {
            if (boxes[i] == boxes[r]) {
                ans = max(ans, dfs(boxes, l, i, k+1) + dfs(boxes, i+1, r-1, 0));
            }
        }
        return ans;
    }
};

int main() {
    Solution s;
    vector<int> boxes = {1, 3, 2, 2, 2, 3, 4, 3, 1};
    cout << s.removeBoxes(boxes) << '\n';
}