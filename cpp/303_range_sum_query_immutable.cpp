#include "header.h"
using namespace std;

class NumArray {
public:
    NumArray(vector<int>& nums) {
        int n = nums.size();        
        sum_ = vector<int>(n+1);
        sum_[n] = 0;
        for (int i=0; i<n; ++i) {
            sum_[n-1-i] = sum_[n-i] + nums[n-1-i];
        }
    }
    
    int sumRange(int i, int j) {
        return sum_[i] - sum_[j+1];
    }
private:
    vector<int> sum_;
};


int main() {
    vector<int> nums = {1,2,3,4,5};
    NumArray* arr = new NumArray(nums);
    int ans = arr->sumRange(0,4);
    cout << ans << '\n';
}