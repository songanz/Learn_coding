#include "header.h"
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ans;
        pair<int, int> temp;
        vector< pair<int,int> > toSort;  // pair是个好东西
        int n = nums.size();

        for (int i = 0; i < nums.size(); i++) {
            temp = make_pair(nums[i], i);
            toSort.push_back(temp);
        }

        sort(toSort.begin(), toSort.end());
        for (int i = 0; i < n-1; i++) {
            for (int j = i+1; j < n; j++) {
                if ((toSort[i].first + toSort[j].first) == target) {
                    ans.push_back(toSort[i].second);
                    ans.push_back(toSort[j].second);                    
                    return ans;
                }
            }
        }
        return ans;
    }
};

int main() {
    Solution s;
    vector<int> nums;
    nums.push_back(0);
    nums.push_back(4);
    nums.push_back(3);
    nums.push_back(0);
    int target = 0;

    cout << s.twoSum(nums, target)[0] << ", " << s.twoSum(nums, target)[1] << endl;
}