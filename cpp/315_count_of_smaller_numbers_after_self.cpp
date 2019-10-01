#include "header.h"
using namespace std;

class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        if (nums.size() == 0) return {};
        vector< pair<int,int> > sorted;
        for (int i=0; i<nums.size(); ++i) {
            sorted.push_back(make_pair(nums[i], i));
        }
        sort(sorted.begin(), sorted.end());
        vector<int> ans(nums.size()+1,0);
        for (int i=0; i<nums.size(); ++i) {
            ans[sorted[i].second] =  
        }
    }
};