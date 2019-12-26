#include "../header.h"
using namespace std;
// two pointer

class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int l_m = 0;
        int r_m = 0;
        int l = 0; 
        int r = n-1;
        int ans = 0;
        while (l<r) {
            if (l_m < height[l]) l_m = height[l];
            if (r_m < height[r]) r_m = height[r];
            if (l_m < r_m) {
                // water at position l is known for sure
                ans += l_m - height[l];
                l += 1;
            }
            else {
                // water at position r is known for sure
                ans += r_m - height[r];
                r -=1;
            }
        }
        return ans;
    }
};


int main() {
    Solution s;
    vector<int> height;

    height.push_back(0);
    height.push_back(1);
    height.push_back(0);
    height.push_back(2);
    height.push_back(1);
    height.push_back(0);
    height.push_back(1);
    height.push_back(3);
    height.push_back(2);
    height.push_back(1);
    height.push_back(2);
    height.push_back(1);

    cout << s.trap(height) << endl;
}