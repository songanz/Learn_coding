# include "header.h"
using namespace std;

/*
Topolocy sort with 
activity of vertex graph
*/

class Solution {
public:
    string alienOrder(vector<string>& words) {
        if (words.size() == 0) return "";
        // else do a topology sort --> build an indegree map
        unordered_map<char, int> m1;
        for (auto word : words) {
            for (auto ch : word) {
                m1[ch] = 0;  // initalize indegree map
            }
        }
        // build a map from a char to all the chars ranked behind it
        unordered_map< char, multiset<char> > m2;
        // get the degree from adjacent words
        for (int i=1; i<words.size(); i++) {
            int indx = 0;
            int l1 = words[i-1].size();
            int l2 = words[i].size();
            while (words[i-1][indx] == words[i][indx]) indx++;
            if (indx >= min(l1, l2)) continue;
            m1[words[i][indx]]++;
            m2[words[i-1][indx]].insert(words[i][indx]);
        }

        // generate the answer
        string ans;
        for (int i=0; i<m1.size(); i++) {
            char ch = ' ';
            for (auto v: m1) {
                if (v.second == 0) {
                    ch = v.first;
                    break;
                }
            }
            if (ch == ' ') return "";
            ans += ch;
            m1[ch]--;  // visited char become -1
            for (auto v: m2[ch]) m1[v]--;  // lower the rank of all the chars ranked behind 
        }
        return ans;
    }
};

int main() {
    Solution s;
    vector<string> words;
    words.push_back("wrt");
    words.push_back("wrf");
    words.push_back("er");
    words.push_back("ett");
    words.push_back("rftt");

    cout << s.alienOrder(words) << '\n';
}