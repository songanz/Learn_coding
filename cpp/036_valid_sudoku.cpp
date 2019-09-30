#include "header.h"
using namespace std;

class Solution {
public:
    bool isValidSudoku(vector< vector<char> >& board) {
        // column
        for (int i=0; i<9; ++i) {
            set<int> temp_ = {};
            for (int j=0; j<9; ++j) {
                if (board[i][j] != '.' && temp_.find(board[i][j]-'0') != temp_.end()) return false;
                if (board[i][j] != '.' && temp_.find(board[i][j]-'0') == temp_.end()) {
                    temp_.insert(board[i][j]-'0');
                }
            }
        }
        // row
        for (int i=0; i<9; ++i) {
            set<int> temp_ = {};
            for (int j=0; j<9; ++j) {
                if (board[j][i] != '.' && temp_.find(board[j][i]-'0') != temp_.end()) return false;
                if (board[j][i] != '.' && temp_.find(board[j][i]-'0') == temp_.end()) {
                    temp_.insert(board[j][i]-'0');
                }
            }
        }
        // cube
        for (int i=0; i<3; ++i) {
            for (int j=0; j<3; ++j) {
                set<int> temp_;
                for (int x=0; x<3; ++x) {
                    for (int y=0; y<3; ++y) {
                        if (board[i*3+x][j*3+y] != '.' && temp_.find(board[i*3+x][j*3+y]-'0') != temp_.end()) return false;
                        if (board[i*3+x][j*3+y] != '.' && temp_.find(board[i*3+x][j*3+y]-'0') == temp_.end()) {
                            temp_.insert(board[i*3+x][j*3+y]-'0');
                        }
                    }
                }
            }
        }
        return true;        
    }
};

// 还可以利用set.insert()的特点
class Solution2 {
public:
  bool isValidSudoku(vector<vector<char> > &board) {        
    for (int i = 0; i < 9;i++) {
      set<char> r, c;
      for (int j = 0; j < 9; j++) {
        // second是一个bool，表示是否insert成功，不成功表示已经有了，成功就表示insert进去了
        if (board[i][j] != '.' && !r.insert(board[i][j]).second)
          return false;
        if (board[j][i] != '.' && !c.insert(board[j][i]).second)
          return false;
      }
    }
 
    for (int p = 0; p < 3; p++)
      for (int q = 0; q < 3; q++) {
        set<char> b;
        for (int i = 0; i < 3; i++)
          for (int j = 0; j < 3; j++) {
            int x = p * 3 + i;
            int y = q * 3 + j;
            if (board[y][x] != '.' && !b.insert(board[y][x]).second)
              return false;
          }
        }
    return true;
  }
};

int main() {
    vector< vector<char> > board = {
  {'5','3','.','.','7','.','.','.','.'},
  {'6','.','.','1','9','5','.','.','.'},
  {'.','9','8','.','.','.','.','6','.'},
  {'8','.','.','.','6','.','.','.','3'},
  {'4','.','.','8','.','3','.','.','1'},
  {'7','.','.','.','2','.','.','.','6'},
  {'.','6','.','.','.','.','2','8','.'},
  {'.','.','.','4','1','9','.','.','5'},
  {'.','.','.','.','8','.','.','7','9'}};
  Solution s;
  cout << s.isValidSudoku(board) << endl;
}