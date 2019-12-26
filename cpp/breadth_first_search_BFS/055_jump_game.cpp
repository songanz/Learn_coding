#include "../header.h"
using namespace std;

// BFS
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int curStep = 0;
        int preStep = 0;
        int indx = 0;  // searching index
        
        while (indx < nums.size()) {
            int i = preStep;
            preStep = curStep;
            for (; i <= preStep; i++){
                curStep = max(curStep, i+nums[i]);
                if ( curStep >= nums.size()-1 ) return true;
            }
            indx++;
        }
        return false;
    }
};


int main() {
    Solution s;
    vector<int> nums1 = {2, 3, 1, 1, 4};  // true
    vector<int> nums2 = {3, 2, 1, 0, 4};  // false

    cout << s.canJump(nums1) << '\n';
    cout << s.canJump(nums2) << '\n';
}