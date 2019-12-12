#include "../header.h"
using namespace std;


class Solution {
public:
    int climbStairs(int n) {
        if (n <= 1) return 1;
        vector<int> f_(n+1, 1);  // 必须要多一位，最后返回的是f_[n]
        for (int i=0; i<n-1; ++i) {
            f_[i+2] = f_[i] + f_[i+1];
        }
        return f_[n];
    }
};

int main() {
    Solution s;
    int ans = s.climbStairs(2);
    cout << ans << '\n';
}