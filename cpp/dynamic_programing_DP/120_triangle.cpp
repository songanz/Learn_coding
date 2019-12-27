#include "../header.h"
using namespace std;

class Solution {
public:
    int minimumTotal(vector< vector<int> >& triangle) {
        int m = triangle.size();
        if (m == 0) return 0;
        if (m == 1) return triangle[0][0];
        
        vector< vector<int> > minSum = triangle;
        for (int i=1; i<m; i++) {
            // 注意j的范围，利用triangle的特征，从0到行数-1(第3行就从0到2)
            for (int j=0; j<m-i; j++) {
                // DP
                minSum[m-i-1][j] = min(minSum[m-i][j], minSum[m-i][j+1]) + triangle[m-i-1][j];
            }
        }
        return minSum[0][0];
    }
};

int main() {
    Solution s;
    vector< vector<int> > triangle = {{2}, {3,4}, {6,5,7}, {4,1,8,3}};
    
    cout << s.minimumTotal(triangle) << '\n';
}