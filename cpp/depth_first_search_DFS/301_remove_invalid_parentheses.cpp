#include "../header.h"
using namespace std;

// DFS
class Solution{
public:
    vector<string> removeInvalidParentheses(string& s) {
        int l = 0;
        int r = 0;
        for (const char ch : s) {
            l += (ch == '(');
            if (l == 0) r += (ch == ')');
            else l -= (ch == ')');
        }

        vector<string> ans;
        dfs(s, 0, l, r, ans);
        return ans;        
    }
private:
    bool isValid(const string& s) {
        int c = 0;
        for (const char ch : s) {
            if (ch == '(') ++c;
            if (ch == ')') --c;
            if (c < 0) return false;
        }
        return c == 0;
    }
    // 必须引用ans，不然push_back不到public的ans
    void dfs(string s, int start, int l, int r, vector<string>& ans) {  // 必须引用ans！！！
        // terminal condition
        if (l==0 && r==0) {
            if (isValid(s)) ans.push_back(s);
            return;
        }
        // recusive 
        for (int i = start; i < s.length(); ++i ) {
            // avoid duplicate result
            if (i != start && s[i] == s[i-1]) continue;
            
            if (s[i] == '(' && l > 0) {
                string curr = s;
                curr.erase(i,1);  // erase one char if (
                dfs(curr, i, l-1, r, ans);
            }
            else if (s[i] == ')' && r > 0) {
                string curr = s;
                curr.erase(i,1);  // erase the )
                dfs(curr, i, l, r-1, ans);
            }
        }
    }
};

 int main() {
    Solution s;
    string ss = "()())()";  //双引号表示字符串
    cout << s.removeInvalidParentheses(ss)[0] << endl;
 }