#include "header.h"
using namespace std;

// two pointer
class Solution {
public:
    vector< vector<int> > threeSum(vector<int>& nums) {
        if (nums.size() <= 2) return {};
        vector< vector<int> > ans;
        int n = nums.size();
        sort(nums.begin(), nums.end());
        for (int i=0; i<n-2; ++i) {
            if (nums[i] > 0) break;
            if (i>0 && nums[i]==nums[i-1]) continue;
            int l = i+1;
            int r = n-1;
            while (l<r) {
                if (nums[i] + nums[l] + nums[r] == 0){
                    ans.push_back({nums[i], nums[l++], nums[r--]});
                    while (l<r && nums[l] == nums[l-1]) ++l;
                    while (l<r && nums[r] == nums[r+1]) --r;
                }
                else if (nums[i] + nums[l] + nums[r] < 0) ++l;
                else --r;
            }
        }
        return ans;
    }
};

int main() {
    Solution s;
    vector<int> nums = {-1, 0, 1, 2, -1, -4};
    cout << s.threeSum(nums)[0][0] << endl;
}