#include "header.h"
using namespace std;

// use union find set
class UnionFindSet {
public:
    // init
    UnionFindSet(int n) {
        ranks_ = vector<int>(n+1, 0);
        parents_ = vector<int>(n+1, 0);
        // 初始化成自己的parent是自己
        for (int i=0; i<parents_.size(); ++i) {
            parents_[i] = i;
        }
    }
    // merge set that contain u and v
    // return true if merged, false if u and v already in one set
    bool Union(int u, int v) {
        int pu = Find(u);
        int pv = Find(v);
        if (pu == pv) return false;
        // merge low rank tree into high rank tree
        if (ranks_[pv] > ranks_[pu]) parents_[pu] =pv;
        else if (ranks_[pv] < ranks_[pu]) parents_[pv] = pu;
        else {
            parents_[pv] = pu;
            ranks_[pv] += 1;
        }
        return true;
    }

    // get the root of u
    int Find(int u) {
        // path compression: 指向最根的节点
        if (u != parents_[u]) parents_[u] = Find(parents_[u]);
        return parents_[u];
    }

private:
    vector<int> ranks_;
    vector<int> parents_;
};

class Solution {
public:
    vector<int> findRedundantConnection(vector< vector<int> >& edges) {
        UnionFindSet s(edges.size());
        
        for (const auto& edge : edges) {
            if (!s.Union(edge[0], edge[1])) return edge;
        }
        return {};
    }
};

int main() {
    vector< vector<int> > edges = {{1,2}, {1,3}, {2,3}};
    Solution s;
    vector<int> ans = s.findRedundantConnection(edges);
    for (int i=0; i<ans.size(); ++i){
        cout << ans[i] << endl;
    }
}