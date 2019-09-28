#include "header.h"
using namespace std;

// 中等难度？？？
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        if (nums.size() == 0) return 0;
        sort(nums.begin(), nums.end(), greater<int>());
        return nums[k-1];
    }
};

int main() {
    vector<int> nums = {3,2,1,5,6,4};
    int k = 2;
    Solution s;
    cout << s.findKthLargest(nums, k) << endl;
}