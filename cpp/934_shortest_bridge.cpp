#include "header.h"
using namespace std;

class Solution {
public:
  int shortestBridge(vector< vector<int> >& A) {
    queue< pair<int, int> > q;
    bool found = false;  // 避免把第二个也找成了小岛
    for (int i = 0; i < A.size() && !found; ++i)
        for (int j = 0; j < A[0].size() && !found; ++j)
            if (A[i][j]) {  // 找到第一个
                dfs(A, j, i, q);
                found = true;
            }

    // BFS
    int steps = 0;
    vector<int> dirs{0, 1, 0, -1, 0};  // 描述direction
    while (!q.empty()) {      
        size_t size = q.size();
        while (size--) {
            // 对于queue里面的每一个节点
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            for (int i = 0; i < 4; ++i) {
                // 使用一维数组可以描述搜索的方向
                int tx = x + dirs[i];
                int ty = y + dirs[i + 1];  
                if (tx < 0 || ty < 0 || tx >= A[0].size() || ty >= A.size() || A[ty][tx] == 2) continue;          
                if (A[ty][tx] == 1) return steps;
                A[ty][tx] = 2;
                q.emplace(tx, ty);
            }
        }
        ++steps;
    }
    return -1;
  }
private:  
    void dfs(vector< vector<int> >& A, int x, int y, queue< pair<int, int> >& q) {
        if (x < 0 || y < 0 || x >= A[0].size() || y >= A.size() || A[y][x] != 1) return;
        A[y][x] = 2;
        q.emplace(x, y);  // push to the end of the queue
        dfs(A, x - 1, y, q);
        dfs(A, x, y - 1, q);
        dfs(A, x + 1, y, q);
        dfs(A, x, y + 1, q);
  }
};

int main() {
    Solution s;
    vector< vector<int> > A = {{0,1,0}, {0,0,0}, {0,0,1}};
    cout << s.shortestBridge(A) << '\n';
}