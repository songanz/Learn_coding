#include "header.h"
using namespace std;

class Solution {
public:
    void rotate(vector< vector<int> >& matrix) {
        if (matrix.size() == 0) return;
        int n = matrix.size();
        for (int i=0; i<n; ++i) {
            for (int j=i; j<n; ++j) {
                int temp = matrix[i][j];
                matrix[i][j] = matrix[j][i];
                matrix[j][i] = temp;
            }
        }
        for (int i=0; i<n; ++i) {
            for (int j=0; j<n/2; ++j) {
                int temp = matrix[i][j];
                matrix[i][j] = matrix[i][n-j-1];
                matrix[i][n-j-1] = temp;
            }
        }
    }
};


int main() {
    vector< vector<int> > matrix = {{1,2,3}, {4,5,6}, {7,8,9}};
    Solution s;
    s.rotate(matrix);
    cout << matrix[0][0] << endl;
}