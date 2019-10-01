#include "header.h"
using namespace std;

// DFS or union find set
class Solution {
public:
    int findCircleNum(vector< vector<int> >& M) {
        if (M.size() <= 1) return 1;
        int n = M.size();
        int ans = 0;
        for (int i=0; i<n; ++i) {
            for (int j=i; j<n; ++j) {
                if (M[i][j] == 1) {
                    ans += 1;
                    dfs(M, i, j, n);
                }
            }
        }
        return ans;
    }
private:
    void dfs(vector< vector<int> >& M, int i, int j, int n) {
        if (i<0 || j<0 || i>=n || j>= n || M[i][j] == 0) return;
        M[i][j] = 0;
        M[j][i] = 0;
        for (int a=0; a<n; ++a) {
            dfs(M, j, a, n);
        }
    }
};

// 第二种：用UFS
class UFS {
public:
    UFS(int n) {
        ranks_ = vector<int>(n+1,0);
        ps_ = vector<int>(n+1,0);
        for (int i=0; i<ps_.size(); ++i) {
            ps_[i] = i;
        }
    }
    bool Union(int u, int v) {
        int pu = Find(u);
        int pv = Find(v);
        if (pu == pv) return false;
        if (ranks_[pv] > ranks_[pu]) ps_[pu] = pv;
        else if (ranks_[pv] < ranks_[pu]) ps_[pv] = pu;
        else {
            // 如果两个一样的rank
            ps_[pu] = pv;
            ranks_[pv]++; // 
        }
        return true;
    }
    int Find(int u) {
        if (ps_[u] != u) ps_[u] = Find(ps_[u]);
        return ps_[u];
    }

private:
    vector<int> ranks_;
    vector<int> ps_;
};

class Solution2 {
public:
    int findCircleNum(vector< vector<int> >& M) {
        if (M.size()<=1) return 1;
        int n = M.size();
        UFS s(n);
        for (int i=0; i<n; ++i) {
            for (int j=i; j<n; ++j) {
                if (M[i][j] == 0) continue;
                s.Union(i,j);
                M[i][j] = 0;
                M[j][i] = 0;
            }
        }
        set<int> ss;
        for (int i=0; i<n; ++i) {
            ss.insert(s.Find(i));
        }
        return ss.size();
    }
};

int main() {
    // vector< vector<int> > M = {{1,1,0}, {1,1,0}, {0,0,1}};
    vector< vector<int> > M = {{1,0,0,1}, {0,1,1,0}, {0,1,1,1}, {1,0,1,1}};
    Solution s;
    cout << s.findCircleNum(M) << endl;
}