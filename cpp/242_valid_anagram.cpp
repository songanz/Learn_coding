#include "header.h"
using namespace std;

class Solution {
    public:
    bool isAnagram(string s, string t) {
        if (s == t) return true;
        if (s.empty() || t.empty()) return false;
        if (s.size() != t.size()) return false;
        int letterCount[256] = {0};
        for (int i = 0; i != s.size(); ++i) {
            ++letterCount[s[i]];
            --letterCount[t[i]];
        }
        for (int i = 0; i != t.size(); ++i) {
            if (letterCount[t[i]] != 0) {
                return false;
            }
        }

        return true; 
    }
};

// 复杂度更高，sort的时间复杂度在O(n)到O(n^2)之间，空间复杂度是O(n)
class Solution2 {
    public:
    bool isAnagram(string s, string t) {
        if (s == t) return true;
        if (s.empty() || t.empty()) return false;
        if (s.size() != t.size()) return false;
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());
        if (s == t) {
            return true;
        }
        else {
            return false;
        }
    }
};

int main() {
    Solution solution;
    cout << solution.isAnagram("anagram","nagaram");
    cout << solution.isAnagram("","");
}