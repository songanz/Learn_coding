#include "header.h"
using namespace std;

class Solution {
public:
    vector<string> reorderLogFiles(vector<string>& logs) {
        vector< pair<char, string> > string_log;
        vector<string> ans;
        for (auto log : logs) {
            int ind = log.find(" ", 0);
            if (isdigit(log[ind+1])) ans.push_back(log);
            else string_log.push_back({log[ind+1], log});
        }
        sort(string_log.begin(), string_log.end());
        for (int i=0; i<string_log.size(); ++i) {
            ans.insert(ans.begin(), string_log[string_log.size()-i-1].second);  // reverse the order
        }
        return ans;
    }
};

int main() {
    Solution s;
    vector<string> logs = {"dig1 8 1 5 1","let1 art can","dig2 3 6","let2 own kit dig","let3 art zero"};
    cout << s.reorderLogFiles(logs)[0] << endl;
}