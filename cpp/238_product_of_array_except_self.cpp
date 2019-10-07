#include "header.h"
using namespace std;


class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        if (nums.size() <= 1) return nums;
        int n = nums.size();
        vector<int> L(n);  // product of the elements on the left of the item
        vector<int> R(n);  // product of the elements on the right of the item
        
        // calculate the L and R
        L[0] = 1;
        R[n-1] = 1;
        for (int i=1; i<n; ++i) {
            L[i] = L[i-1]*nums[i-1];
            R[n-1-i] = R[n-i]*nums[n-i];
        }
        vector<int> ans;
        for (int i=0; i<n; ++i) {
            ans.push_back(L[i]*R[i]);
        }
        return ans;        
    }
};

int main() {
    Solution s;
    vector<int> nums = {1,2,3,4};
    cout << s.productExceptSelf(nums)[0] << '\n';
}