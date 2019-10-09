#include "header.h"
using namespace std;

// DP
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> f(n);
        f[0] = nums[0];

        for (int i=1; i<n; ++i) {
            // 如果前面加起来还不如num[i]，那就重新开始算
            f[i] = max(f[i-1] + nums[i], nums[i]);
        }
        return *max_element(f.begin(),f.end());
    }
};


int main() {
    Solution s;
    vector<int> nums;
    nums.push_back(-2);
    nums.push_back(1);
    nums.push_back(-3);
    nums.push_back(4);
    nums.push_back(-1);
    nums.push_back(2);
    nums.push_back(1);
    nums.push_back(-5);
    nums.push_back(4);
    cout << s.maxSubArray(nums) << endl;
}