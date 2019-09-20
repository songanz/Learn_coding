#include "header.h"
using namespace std;

class Solution {
public:
    int maxPoints(vector< vector<int> >& points) {
        int n = points.size();
        if (n == 1) return 1;
        int ans = 0;

        for (int i = 0; i < n-1; i++) {
            map < pair <int, int> ,int > count;  // map 很方便查找元素，用斜率当key
            int same_p = 1;
            int max_p = 0;  // 临时最优解
            vector<int> p1;
            p1.push_back(points[i][0]);
            p1.push_back(points[i][1]);
            for (int j = i+1; j < n; j++) {
                vector<int> p2;
                p2.push_back(points[j][0]);
                p2.push_back(points[j][1]);

                if (p1[0] == p2[0] && p1[1] == p2[1]) 
                    ++same_p;
                else
                    max_p = max(max_p, ++count[getSlope(p1,p2)]);
            }
            ans = max(ans, max_p + same_p);
        }
        return ans;        
    }
private:
    pair <int, int> getSlope(vector<int> &p1, vector<int> &p2){
        pair <int, int> ans;
        const int dx = p2[0] - p1[0];
        const int dy = p2[1] - p1[1];

        if (dx == 0) {
            ans = make_pair(0, p1[0]);
            return ans;
        }
        if (dy == 0) {
            ans = make_pair(p1[1], 0);
            return ans;
        } 

        const int d = __gcd(dx, dy);  // greatest common divisor 要把最大公约数除掉！
        ans = make_pair(dy/d, dx/d);
        return ans;
    }
};

int main() {
    Solution s;
    vector<vector<int> > points;
    vector<int> temp;

    temp.push_back(1);
    temp.push_back(1);
    points.push_back(temp);
    temp.clear();

    temp.push_back(2);
    temp.push_back(2);
    points.push_back(temp);
    temp.clear();

    temp.push_back(3);
    temp.push_back(3);
    points.push_back(temp);
    temp.clear();

    cout << s.maxPoints(points) << endl;
}