#include "header.h"
using namespace std;

// Array 小心overflow！！！！
class Solution {
public:
    
    string rts(int lo, int hi) {
        return (lo == hi) ? to_string(lo) : (to_string(lo) + "->" + to_string(hi));
    }
    
    vector<string> findMissingRanges(vector<int>& nums, int lower, int upper) {
        
        vector<string> aResult;
        long long aPrev = lower;
        
        for (int i=0;i<nums.size();i++) {
            
            if (nums[i] < aPrev) { continue; }
            
            if (nums[i] == aPrev) {
                aPrev++;
                continue;
            }
            
            aResult.push_back(rts(aPrev, ((long long)nums[i]) - 1));    
            aPrev = ((long long)nums[i]) + 1;
        }
        
        if (aPrev <= upper) {
            aResult.push_back(rts(aPrev, upper));
        }
        
        return aResult;
    }
};

int main () {
    Solution s;
    vector<int> nums;
    nums.push_back(-2147483648);
    nums.push_back(2147483647);
    // nums.push_back(0);
    // nums.push_back(1);
    // nums.push_back(3);
    // nums.push_back(50);
    // nums.push_back(75);
    cout << s.findMissingRanges(nums, -2147483648, 2147483647)[0] << endl;
    // cout << s.findMissingRanges(nums, 0, 99)[0] << endl;
}