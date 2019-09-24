#include "header.h"
using namespace std;

// priority_queue: 可以自己定义优先级 <Type, Container, Functional>
// Container必须是用数组实现的容器，比如vector, deque等等, 但不能用 list
class Solution {
public:
    int minMeetingRooms(vector< vector<int> >& intervals) {
        // corner case
        if (intervals.empty() || intervals.size() == 0) return 0;
        int res = 0;
        int n = intervals.size();
        // sort starting time
        sort(intervals.begin(), intervals.end());
        // create priority queue on end time
        // 如果要用到小顶堆(升序)，则一般要把模板的3个参数都带进去
        // STL里面定义了一个仿函数greater<>，基本类型可以用这个仿函数声明小顶堆
        // 如果不定义就是降序
        priority_queue<int, vector<int>, greater<int> > pq;
        pq.push(intervals[0][1]);
        int s = pq.size();
        res = max(res, s);
        for (int i=1; i<n; ++i) {
            if (intervals[i][0] >= pq.top()) pq.pop(); 
            pq.push(intervals[i][1]);
            s = pq.size();
            res = max(res, s);
        }

        return res;
    }
};

int main() {
    Solution s;
    vector< vector<int> > intervals;
    vector<int> temp;

    temp = {0, 30};
    intervals.push_back(temp);
    temp.clear();

    temp = {15, 20};
    intervals.push_back(temp);
    temp.clear();

    temp = {5, 10};
    intervals.push_back(temp);
    temp.clear();

    cout << s.minMeetingRooms(intervals) << endl;

}