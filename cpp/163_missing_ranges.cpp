#include "header.h"
using namespace std;

// Array
class Solution {
public:
    vector<string> findMissingRanges(vector<int>& nums, int lower, int upper) {
        // corner cases
        vector<string> s;
        if (nums.empty()) {
            string ss = to_string(lower);
            ss += "->";
            ss += to_string(upper);
            s.push_back(ss);
            return s;
        }
        nums.insert(nums.begin(), lower-1);
        nums.push_back(upper+1);
        int n = nums.size();
        int l = lower;
        for (int i=0; i<n; ++i) {
            if (nums[i]-l==1) l = nums[i];
            if (nums[i]-l==2) {
                string ss = to_string(l+1);
                s.push_back(ss);
                l = nums[i];
            }
            if (nums[i]-l>2) {
                string ss = to_string(l+1);
                ss += "->";
                ss += to_string(nums[i]-1);
                s.push_back(ss);
                l = nums[i];
            }
        }
        return s;       
    }
};