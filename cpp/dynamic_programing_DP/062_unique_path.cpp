#include "../header.h"
using namespace std;

class Solution {
public:
    int uniquePaths(int m, int n) {
        if (m <= 0 || n <= 0) return 0;
        vector< vector<int> > m_(n+1, vector<int>(m+1, INT32_MIN));
        return paths(m, n, m_);
    }
private:
    int paths(int m, int n, vector< vector<int> >& m_) {
        if (m<=0 || n<=0) return 0;
        if (m==1 && n==1) return 1;
        if (m_[n][m] != INT32_MIN) return m_[n][m];
        m_[n][m] = paths(m-1, n, m_) + paths(m, n-1, m_);
        return m_[n][m];
    }
};

int main() {
    Solution s;
    cout << s.uniquePaths(5,4) << endl;
}