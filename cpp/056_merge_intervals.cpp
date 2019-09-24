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
        ans.push_back({start, end});
        return ans;
    }
};

int main() {
    vector< vector<int> > intervals;
    Solution s;
    intervals = {{1,3}, {2,6}, {8, 10}, {15, 18}};
    cout << s.merge(intervals)[0][1] << endl;
}