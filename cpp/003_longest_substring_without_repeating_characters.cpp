#include "header.h"
using namespace std;

// 双指针
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.size()==0) return 0;
        int st = 0;  // 起始位置
        int length = 0;
        for (int i=0; i<s.size(); ++i) {
            if (m.count(s[i])==0) {
                m[s[i]] = i;
                length = max(length, i-st+1);
            }
            else {
                st = max(st, m[s[i]]+1);  // 小心，st可能会晚于char最后一次出现的位置
                length = max(length, i-st+1);
                m[s[i]] = i;
            }
        }

        return length;
    }
private:
    // hashmap存char最后一次出现的位置
    unordered_map<char, int> m;
};

int main() {
    string ss = "tmmzuxt";
    Solution s;
    cout << s.lengthOfLongestSubstring(ss) << endl;
}