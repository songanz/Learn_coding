#include "../header.h"
using namespace std;
// BFS

class Solution {
public:
    int jump(vector<int>& nums) {
        // Time complexity: O(N) Space complexity: O(1)
       int curStep = 0, i = 0, level = 0;
            
        while(curStep < nums.size()-1) {
            level++; // BFS level
            int preStep = curStep; // update preStep
            for(; i <= preStep; ++i) { 
                // traverse of preStep level and find the max step of this level
                curStep = max(curStep, i+nums[i]);
            }
        }
        
        return level;
    }
};



int main() {
    Solution s;
    vector<int> nums = {2,3,1,1,4};
    cout << s.jump(nums) << '\n';
}