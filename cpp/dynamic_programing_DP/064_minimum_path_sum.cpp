#include "../header.h"
using namespace std;

class Solution {
public:
    int minPathSum(vector< vector<int> >& grid) {
        int m = grid.size();
        if (m == 0) return 0;
        int n = grid[0].size();
        if (n == 0) return 0;
        if (m==1 & n==1) return grid[0][0];
        
        vector< vector<int> > countSum(m, vector<int>(n, 0));
        for (int i=0; i<m; ++i) {
            for (int j=0; j<n; ++j) {
                if (i==0 & j==0) {
                    countSum[m-1][n-1] = grid[m-1][n-1];
                    continue;
                }
                // 边界条件
                if (i == 0) countSum[m-i-1][n-j-1] = countSum[m-i-1][n-j] + grid[m-i-1][n-j-1];
                else if (j == 0) countSum[m-i-1][n-j-1] = countSum[m-i][n-j-1] + grid[m-i-1][n-j-1];
                // DP
                else countSum[m-i-1][n-j-1] = 
                min(countSum[m-i-1][n-j], countSum[m-i][n-j-1]) 
                + grid[m-i-1][n-j-1];
            }
        }
        return countSum[0][0];
    }
};

int main() {
    Solution s;
    vector< vector<int> > grids = {{1,3,1}, {1,5,1}, {4,2,1}};
    cout << s.minPathSum(grids) << '\n';
}