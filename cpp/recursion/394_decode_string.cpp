#include "../header.h"
using namespace std;

class Solution {
public:
    string decodeString(string s) {
        if (s.size()==0) return s;
        int i = 0;
        int n = s.size();
        int num = 0;
        while(isdigit(s[i])) {
            num = num*10 + (s[i++]-'0');
        }
        // 第一个不是number, 找到第一个number,做recursive
        if (i==0) {
            while (i < n-1 && !isdigit(s[i])) ++i;
            // 如果找完了都没有数字，就返回本来的string
            if (i == n-1) return s;
            return s.substr(0, i) + decodeString(s.substr(i));
        }

        // 第一部分是数字, 后面一定是一个'[', 否则不valid
        // 找到对应的']'
        int j = i;
        if (i+1 < n && s[i] == '[') {
            int open_ = 1;
            while (j < n) {
                j++;
                if (s[j] == '[') open_ += 1;
                if (s[j] == ']') open_ -= 1;
                if (open_ == 0) break;
            }
        }
        // do recursion
        string ans = "";
        int x = 0;
        while (x < num) {
            ++x;
            ans += decodeString(s.substr(i+1, j-i-1));
        }
        // 还有后面的
        ans += decodeString(s.substr(j+1));
        return ans;
    }
};

int main() {
    string ss = "3[a]2[bc]";
    Solution s;
    cout << s.decodeString(ss) << endl;
}