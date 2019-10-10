#include "header.h"
using namespace std;

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        if (n < 1) return {};
        vector<string> ans;
        string cur = "";
        dfs(n, 0, ans, cur);
        return ans;
    }
private:
    void dfs(int n, int r, vector<string>& ans, string& cur) {
        // boundary condition
        if (n==0 && r==0) {
            ans.push_back(cur);
            return;
        }
        if (n<0 || r<0) return;
        // add a '('
        cur += '(';
        dfs(n-1, r+1, ans, cur);
        cur.pop_back();
        // add a ')'
        cur += ')';
        dfs(n, r-1, ans, cur);
        cur.pop_back();
        return;
    }
};

int main() {
    Solution s;
    vector<string> ans = s.generateParenthesis(3);
    for (int i=0; i<ans.size(); ++i){
        cout << ans[i] << '\n';
    }
}