#include "header.h"
using namespace std;

// hashmap + DP 的题
class Solution {
public:
    int numDecodings(string s) {
        if (s.size() == 0) return 0;
        m_ways[""] = 1;
        return ways(s);
    }
private:
    int ways(const string& s) {
        if (m_ways.count(s)) return m_ways[s];  // O(1)搜索
        if (s[0] == '0') return 0;
        if (s.size() == 1) return 1;

        // recursion
        int w = ways(s.substr(1));  // 第一位取出来
        // 已知第一位不是0， convert string to integer
        const int pre = stoi(s.substr(0,2));  

        if (pre <= 26) {
            w += ways(s.substr(2));
        }

        // 存 hashmap
        m_ways[s] = w;

        return w;
    }
    // hashmap 记录已经搜过的string，加速搜索
    unordered_map<string, int> m_ways; // key是搜的string，int是有几种
};

// 只用DP...网上的又快又好
class Solution2 {
public:
    int numDecodings(string s) {
        int n = s.size();
        if(!n || s[0] == '0') return 0;
        int f[n+1] = {1, 1}, i;
        // DP
        for(i = 2; i <= n; ++i)
            f[i] = (int)(s[i-1] != '0')*f[i-1] + (int)((s[i-2] == '1') || (s[i-2] == '2' && s[i-1] < '7'))*f[i-2];
        return f[n];
    }
};

int main() {
    Solution s;
    Solution2 s2;
    string ss = "12";
    cout << s.numDecodings(ss) << endl;
    cout << s2.numDecodings(ss) << endl;
}