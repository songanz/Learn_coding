#include "header.h"
using namespace std;

// 二维DP

class Solution {
public:
    string longestPalindrome(string s) {
        if (s.length() == 0) return s;
        int max_l = 0;
        int n = s.length();
        string res = "";
        bool dp[n][n];  // 空间复杂度O(n^2)

        for (int i = 0; i < n; i++) {
            for (int j = 0; j <= i; j++) {
                dp[i][j] = s.at(i) == s.at(j) && ((i-j <=2) || dp[i-1][j+1]);
                if (i-j+1 > max_l && dp[i][j]) {
                    max_l = i-j+1;
                    res = s.substr(j,max_l);  // 小心，第二个是长度
                }
            }
        }
        return res;        
    }
};

int main() {
    Solution s;
    string st = "babad";
    cout << s.longestPalindrome(st) << endl;
}