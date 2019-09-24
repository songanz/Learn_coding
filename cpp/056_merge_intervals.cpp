#include "header.h"
using namespace std;

class Solution {
public:
    vector< vector<int> > merge(vector< vector<int> >& intervals) {
        // corner cases
        if (intervals.size() <= 1) return intervals;
        // sort starting time
        sort(intervals.begin(), intervals.end());
        // store end time
        priority_queue<int, vector<int>, greater<int> > pq;
        pq.push(intervals[0][1]);
        vector< vector<int> > ans;
        int start = intervals[0][0];
        int end = intervals[0][1];

        for (int i=1; i<intervals.size(); ++i) {
            if (intervals[i][0] <= end && intervals[i][1] > end) {
                end = intervals[i][1];
            }
            else if (intervals[i][0] > end) {
                ans.push_back({start, end});
                start = intervals[i][0];
                end = intervals[i][1];
            }
        }
    }
};

int main() {
    vector< vector<int> > intervals;
    Solution s;
    cout << s.merge(intervals)[0][0] << endl;
}