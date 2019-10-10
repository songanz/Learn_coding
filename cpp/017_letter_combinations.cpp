#include "header.h"
using namespace std;

// backtracking 是 DFS 的一种表现形式
class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if (digits.size() == 0) return {};
        vector< vector<char> > m_;
        m_ = {{' '}, {}, {'a', 'b', 'c'}, {'d', 'e', 'f'},\
        {'g', 'h', 'i'}, {'j', 'k', 'l'}, {'m', 'n', 'o'},\
        {'p', 'q', 'r', 's'}, {'t', 'u', 'v'}, {'w', 'x', 'y', 'z'}};
        string cur;
        vector<string> ans;
        dfs(digits, ans, cur, m_);
        return ans;
    }
private:
    void dfs(string& digits, vector<string>& ans, string& cur, vector< vector<char> > m_) {
        if (cur.size() == digits.size()) {
            ans.push_back(cur);
            return;
            }
        int num = digits[cur.size()]-'0';  // 小心记得转int
        for (char s : m_[num]) {
            cur += s;
            dfs(digits, ans, cur, m_);
            cur.pop_back();
        } 
    }
};

int main() {
    Solution s;
    string digits = "23";
    cout << s.letterCombinations(digits)[0] << endl;
}