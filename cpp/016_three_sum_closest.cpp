#include "header.h"
using namespace  std;

// two pointer
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int ans = nums[0] + nums[1] + nums[2];
        if (ans>=target) return ans;
        for (int i=0; i<n-2; ++i) {
            int l = i+1;
            int r = n-1;
            while (l<r) {
                if (abs(target-ans)>abs(target-nums[i]-nums[l]-nums[r])) ans = nums[i]+nums[l]+nums[r];
                if (nums[i]+nums[l]+nums[r]>target) --r; 
                else if (nums[i]+nums[l]+nums[r]<target) ++l;
                else return target;
            }
        }
        return ans;
    }
};

int main() {
    Solution s;
    vector<int> nums = {-1, 2, 1, -4};
    cout << s.threeSumClosest(nums, 1) << endl;
}