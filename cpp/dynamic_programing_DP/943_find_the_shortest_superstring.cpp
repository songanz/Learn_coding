
#include "../header.h"
using namespace std;

// DP
// Author: Huahua, running time: 20 ms
class Solution {
public:
  string shortestSuperstring(vector<string>& A) {        
    const int n = A.size();
    vector< vector<int> > g(n, vector<int>(n));

    // calculate the cost of each pair: A[i] --> A[j] diff from A[j] --> A[i]
    for (int i = 0; i < n; ++i)
      for (int j = 0; j < n; ++j) {
        g[i][j] = A[j].length();
        for (int k = 1; k <= min(A[i].length(), A[j].length()); ++k)
          if (A[i].substr(A[i].size() - k) == A[j].substr(0, k)) 
            g[i][j] = A[j].length() - k;
      }
    
    // 2-dim DP, don't care about the order, just the last string maters
    // key is the encoded visited strings (by binary): 2^n
    // second element is the last string index: n
    vector< vector<int> > dp(1 << n, vector<int>(n, INT32_MAX / 2));  // bit move
    // parent state which state it transform from
    vector< vector<int> > parent(1 << n, vector<int>(n, -1));

    // init
    for (int i = 0; i < n; ++i) dp[1 << i][i] = A[i].length();
    
    for (int s = 1; s < (1 << n); ++s) {  // state from small to large 
      for (int j = 0; j < n; ++j) {
        if (!(s & (1 << j))) continue;
        int ps = s & ~(1 << j);
        for (int i = 0; i < n; ++i) {
          if (dp[ps][i] + g[i][j] < dp[s][j]) {
            dp[s][j] = dp[ps][i] + g[i][j];
            parent[s][j] = i;
          }
        }
      }
    }
    
    // 恢复路径
    auto it = min_element(begin(dp.back()), end(dp.back()));
    int j = it - begin(dp.back());
    int s = (1 << n) - 1;
    string ans;
    while (s) {  // 倒推路径
      int i = parent[s][j];
      if (i < 0) ans = A[j] + ans;
      else ans = A[j].substr(A[j].length() - g[i][j]) + ans;
      s &= ~(1 << j);
      j = i;
    }
    return ans;
  } 
};

int main(){
    Solution s;
    vector<string> A = {"bad", "ads", "dsg", "gg"};

    cout << s.shortestSuperstring(A) << '\n';
}