#include "header.h"
using namespace std;

class Solution {
public:
    vector<int> findOrder(int n, vector<vector<int>>& pre) {
        if (n == 0) return vector<int>();
        if (n == 1) return vector<int>{0};
        unordered_map <int, int> indegree;
        unordered_map < int, multiset<int> > courseMap;
        for (int i=0; i<n; i++) indegree[i] = 0;
        for (int i=0; i<pre.size(); i++) {
            indegree[pre[i][0]]++;
            courseMap[pre[i][1]].insert(pre[i][0]);
        }
        
        vector<int> ans;
        for (int i=0; i<n; i++){
            int course = -1;
            for (auto v : indegree) {
                if (v.second == 0) {
                    course = v.first;
                    break;
                }
            }
            if (course == -1) return vector<int>();
            ans.push_back(course);
            indegree[course]--;
            for (auto v: courseMap[course]) indegree[v]--;
        }
        return ans;
    }
};


int main() {
    Solution s;
    vector< vector<int> > prerequisite;
    prerequisite.push_back(vector<int>{1,0});
    vector<int> ans = s.findOrder(2, prerequisite);
    if (ans.size() == 0) cout << "EMPTY";
    for (int i=0; i<ans.size(); i++) {
        cout << ans[i] << ", ";
    }
    cout << '\n';
}