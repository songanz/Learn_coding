#include "header.h"
using namespace std;

class Solution {
public:
    bool exist(vector< vector<char> >& board, string word) {
        if (board.size() == 0 ^ word.size() == 0) return false;
        if (board.size() == 0 && word.size() == 0) return true;
        if (board.size()*board[0].size() < word.size()) return false;
        for (int x=0; x<board.size(); ++x) {
            for (int y=0; y<board[0].size(); ++y) {
                if (dfs(board, word, x, y, 0)) {
                   return true;
                }
            }
        }
        return false;
    }
private:
    bool dfs(vector< vector<char> >& board, string& word, int x, int y, int s) {
        if (s == word.size()) return true;
        if (x<0 || y<0 || x>=board.size() || y>=board[0].size() || board[x][y] == '0') return false;
        if (board[x][y] != word[s]) return false;
        else {
            board[x][y] = '0';  // the letter cannot be used onece
            bool ans = dfs(board, word, x-1, y, s+1) || dfs(board, word, x+1, y, s+1) \
            || dfs(board, word, x, y-1, s+1) || dfs(board, word, x, y+1, s+1);
            board[x][y] = word[s];  // for next (for) loop in the "exist" function, change back !!!
            return ans;
        }
    }
};

int main() {
    Solution s;
    vector< vector<char> > board;
    string word="AAB";
    // string word="ABCCED";
    // string word="ab";
    // board.push_back({'A', 'B', 'C', 'E'});
    // board.push_back({'S', 'F', 'C', 'S'});
    // board.push_back({'A', 'D', 'E', 'E'});
    // board.push_back({'a'});
    board.push_back({'C', 'A', 'A'});
    board.push_back({'A', 'A', 'A'});
    board.push_back({'B', 'C', 'D'});
    cout << s.exist(board, word) << endl;
}