#include "header.h"
using namespace std;

class Solution {
public:
    int uniquePathsWithObstacles(vector< vector<int> >& obstacleGrid) {
        int n = obstacleGrid.size();
        if (n == 0) return 0;
        int m = obstacleGrid[0].size();
        
        // f[i][j] = paths(i, j)
        // INT_MIN -> not solved yet, solution unknown
        f_ = vector< vector<int> >(n + 1, vector<int>(m + 1, INT32_MIN));        
        return paths(m, n, obstacleGrid);
    }
private:
    vector< vector<int> > f_;
    
    int paths(int x, int y, const vector< vector<int> >& o) {
        // Out of bound, return 0.
        if (x <= 0 || y <= 0) return 0;
        
        // Reaching the starting point.
        // Note, there might be an obstacle here as well.
        if (x == 1 && y == 1) return 1 - o[0][0];
        
        // Already solved, return the answer.
        if (f_[y][x] != INT32_MIN) return f_[y][x];
        
        // There is an obstacle on current block, no path
        if (o[y - 1][x - 1] == 1) {
            f_[y][x] = 0;
        } else {
            // Recursively find paths.
            f_[y][x] = paths(x - 1, y, o) + paths(x, y - 1, o);
        }
        
        // Return the memorized answer.
        return f_[y][x];
    }
};


int main() {
    // vector< vector<int> > obstacleGrid = {{0,0,0}, {0,1,0}, {0,0,0}};
    vector< vector<int> > obstacleGrid = {{0}};
    Solution s;
    cout << s.uniquePathsWithObstacles(obstacleGrid) << endl;
}