#include "header.h"
using namespace std;

class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        int dx[4] = {0, 1, 0, -1};
        int dy[4] = {1, 0, -1, 0};
        int x = 0, y = 0, di = 0;

        // set 可以容易的找元素，如果是vector< vector<int> >, 不能找vector<int>!!!
        // 但是又还不需要unordered_map
        set<pair<int, int>> obstacleSet;
        for (vector<int> obstacle: obstacles)
            obstacleSet.insert(make_pair(obstacle[0], obstacle[1]));

        int ans = 0;
        for (int cmd: commands) {
            // 判断方向
            if (cmd == -2)
                di = (di + 3) % 4;
            else if (cmd == -1)
                di = (di + 1) % 4;
            else {
                for (int k = 0; k < cmd; ++k) {
                    int nx = x + dx[di];  // 试着动
                    int ny = y + dy[di];
                    //没有的话真的动
                    if (obstacleSet.find(make_pair(nx, ny)) == obstacleSet.end()) {
                        x = nx;
                        y = ny;
                        ans = max(ans, x*x + y*y);
                    }
                }
            }
        }
        return ans;
    }
};


int main() {
    Solution s;
    // vector<int> commands = {4, -1, 4, -2, 4};
    vector<int> commands = {7, -2, -2, 7, 5};
    // vector< vector<int> > obstacles = {{2,4}};
    // vector< vector<int> > obstacles = {{-4,-1},{1,-1},{1,4},{5,0},{4,5},\
    {-2,-1},{2,-5},{5,1},{-3,-1},{5,-3}};
    vector< vector<int> > obstacles = {{-3,2},{-2,1},{0,1},{-2,4},{-1,0},\
    {-2,-3},{0,-3},{4,4},{-3,3},{2,2}};

    cout << s.robotSim(commands, obstacles) << endl;
}