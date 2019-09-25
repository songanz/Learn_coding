#include "header.h"
using namespace std;

class Solution {
public:
    bool isHappy(int n) {
        if (n == 1) return true;
        unordered_map<int, int> m;
        while (true)
        {
            string num = to_string(n);
            int ans = 0;
            for (int i=0; i<num.size(); ++i) {
                ans += int(num[i]-'0') *int(num[i]-'0');
            }
            if (ans == 1) return true;
            if (m.find(ans) == m.end()) {
                m[ans] = 0;
                n = ans;
            }
            else return false; 
        }
    }
};

int main() {
    Solution s;
    int k = 19;
    cout << s.isHappy(k) << endl;
}