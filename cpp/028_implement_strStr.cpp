#include "header.h"
using namespace std;

class Solution {
public:
    int strStr(string haystack, string needle) {
        if (needle.empty() || haystack == needle) return 0;
        if (haystack.empty()) return -1;
        if (haystack.size() < needle.size()) return -1;

        for (string::size_type i = 0; i < haystack.size() - needle.size() + 1; i++) {
            string::size_type j = 0;
            for (; j < needle.size(); j++) {
                if (haystack[i + j] != needle[j]) break;
            }
            if (j == needle.size()) return i;
        }
        return -1;
    }
};

int main() {
    Solution s;
    cout << s.strStr("hello", "ll") << "\n";
    cout << s.strStr("", "") << "\n";
    cout << s.strStr("a", "a") << "\n";
    cout << s.strStr("mississippi","pi") << "\n";
}
