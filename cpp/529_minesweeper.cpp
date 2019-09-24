#include "header.h"
using namespace std;

// 扫雷
class Solution {
public:
    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
        const int m = board.size();
        const int n = board[0].size();

        if (board[click[0]][click[1]]=='M') {
            board[click[0]][click[1]] = 'X';
            return board;
        }
        if (board[click[0]][click[1]]=='E') {
            dfs(board, click, m, n);
        }
        return board;  
    }
private:
    void dfs(vector<vector<char>>& board, vector<int>& click, const int m, const int n) {
        if (click[0]<0 || click[1]<0 || click[0]>=m || click[1]>=n || board[click[0]][click[1]] == 'B') return;
        vector< vector<int> > p = \
        {{click[0]-1, click[1]-1}, {click[0], click[1]-1}, {click[0]+1, click[1]-1}, \
        {click[0]-1, click[1]}, {click[0]+1, click[1]}, \
        {click[0]-1, click[1]+1}, {click[0], click[1]+1}, {click[0]+1, click[1]+1}};
        // 两种情况
        // 1. 附近有雷 --> 改成数字，return board   
        // 2. 附近没有雷 --> 都改成'B'，并DFS搜索附近
        char c = count_nei(board, p, m, n);
        if (c != '0') {
            board[click[0]][click[1]] = count_nei(board, p, m, n);
            return;
        }
        if (c == '0') {
            board[click[0]][click[1]] = 'B';
            for (vector<int> pp:p) {
                dfs(board, pp, m, n);
            }
        }
    }
private:
    char count_nei(vector<vector<char>>& board, vector< vector<int> > p, int m, int n) {
        int count = 0;
        for (vector<int> pp : p) {
            if (pp[0]<0 || pp[1]<0 || pp[0]>=m || pp[1]>=n) continue;
            if (board[pp[0]][pp[1]]=='M') {
                count += 1;
            }
        }
        char c = count + '0';
        return c;
    }
};

int main() {
    vector<vector<char>> board;
    Solution s;
    vector<int> click = {3,0};
    vector<char> temp = {'E', 'E', 'E', 'E', 'E'};
    board.push_back(temp);
    temp.clear();

    temp = {'E', 'E', 'M', 'E', 'E'};
    board.push_back(temp);
    temp.clear();

    temp = {'E', 'E', 'E', 'E', 'E'};
    board.push_back(temp);
    temp.clear();

    temp = {'E', 'E', 'E', 'E', 'E'};
    board.push_back(temp);
    temp.clear();

    cout << s.updateBoard(board, click)[click[0]][click[1]] << endl;
}