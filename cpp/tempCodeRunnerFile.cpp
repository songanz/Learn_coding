public:
    vector<string> letterCombinations(string digits) {
        if (digits.size() == 0) return {""};
        vector< vector<char> > m_;
        m_ = {{' '}, {}, {'a', 'b', 'c'}, {'d', 'e', 'f'},\
        {'g', 'h', 'i'}, {'j', 'k', 'l'}, {'m', 'n', 'o'},\
        {'p', 'q', 'r', 's'}, {'t', 'u', 'v'}, {'w', 'x', 'y', 'z'}};
        string cur;
        vector<string> ans;
        dfs(digits, ans, cur, m_, 0);
        return ans;
    }
private:
    void dfs(string& digits, vector<string>& ans, string cur, vector< vector<char> > m_, int l) {
        if (cur.size() == digits.size()) {
            ans.push_back(cur);
            return;
            }
        int num = digits[cur.size()-1]-'0';
        cur += m_[num][l];
        dfs(digits, ans, cur, m_, l+1);
    }
};