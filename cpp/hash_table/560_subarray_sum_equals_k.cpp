#include "../header.h"
using namespace std;

// 想知道为什么就debug看一下
class Solution {
public:
  int subarraySum(vector<int>& nums, int k) {
    if (nums.empty()) return 0;
    unordered_map<int, int> counts{{0,1}};  // key存的是之前的sum，第二位存1
    int cur_sum = 0;
    int ans = 0;
    for (const int num : nums) {
      cur_sum += num;      
      ans += counts[cur_sum - k];  // unordered_map 帮忙用key找，省下来一个loop， hashtable O(1)省空间
      ++counts[cur_sum];
    }
    return ans;
  }
};


int main() {
    Solution s;
    vector<int> nums={1,2,3,4};
    int k = 4;
    cout << s.subarraySum(nums, k) << endl;
}