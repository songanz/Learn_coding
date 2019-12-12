#include "../header.h"
using namespace std;

// 这个跑不动
class Solution {
public:
    void solveSudoku(vector< vector<char> >& board) {
        int count = 0;
        map< int, set<int> > r_;
        map< int, set<int> > c_;
        map< int, set<int> > b_;
        for (int p = 0; p < 3; p++)
            for (int q = 0; q < 3; q++) {
                for (int i = 0; i < 3; i++)
                    for (int j = 0; j < 3; j++) {
                        int x = p * 3 + i;
                        int y = q * 3 + j;
                        if (board[x][y] == '.') {
                            count += 1;
                        }
                        else {
                            b_[p*3+q].insert(board[x][y] - '0');
                            r_[x].insert(board[x][y] - '0');
                            c_[y].insert(board[x][y] - '0');
                        }
                    }
            }

        if (count == 0) return;
        dfs(board, count, r_, c_, b_);
        return;
    }
private:
    void dfs(vector< vector<char> >&  board, int count, 
    map< int, set<int> >& r_, map< int, set<int> >& c_, map< int, set<int> >& b_) {
        if (count == 0) return;
        for (int p = 0; p < 3; p++) {
            for (int q = 0; q < 3; q++) {
                for (int i = 0; i < 3; i++)
                    for (int j = 0; j < 3; j++) {
                        int x = p * 3 + i;
                        int y = q * 3 + j;
                        if (board[x][y] == '.') {
                            for (int k=1; k<=9; ++k) {
                                if (b_[p*3+q].count(k) == 0 
                                && r_[x].count(k) == 0 
                                &&  c_[y].count(k) == 0) {
                                    b_[p*3+q].insert(k);
                                    r_[x].insert(k);
                                    c_[y].insert(k);
                                    board[x][y] = '0' + k;
                                    dfs(board, count-1, r_, c_, b_);
                                    board[x][y] = '.';
                                    b_[p*3+q].erase(k);
                                    r_[x].erase(k);
                                    c_[y].erase(k);
                                }
                            }
                        }
                    }
            }
        }
    }
};

class Solution2 {
private:
	vector<vector<bool>>row;//row[i][j]表示第i行已经有了j+1这个数字
	vector<vector<bool>>col;//col[i][j]表示第i列已经有了j+1这个数字
	vector<vector<vector<bool>>>cube;//把9X9分成3x3x9个
	//cube[i][j][k]表示第i行第j列的3*3已经有了k+1这个数字
public:
	void solveSudoku(vector<vector<char>>& board) {
		row = vector<vector<bool>>(9, vector<bool>(9, false));
		col = vector<vector<bool>>(9, vector<bool>(9, false));
		cube = vector<vector<vector<bool>>>(3, vector<vector<bool>>(3, vector<bool>(9, false)));
		int n = 0;
		for (int i = 0; i < 9; i++) {
			for (int j = 0; j < 9; j++) {
				if (board[i][j] != '.') {
					row[i][board[i][j] - '1'] = true;
					col[j][board[i][j] - '1'] = true;
					cube[i / 3][j / 3][board[i][j] - '1'] = true;
					n++;
				}
			}
		}
		n = 81 - n;//需要填写数字的个数
		DFS(0, n, board);
		return;
	}
	bool DFS(int index, int n, vector<vector<char>>& board) {
		if (n == 0) {
			return true;
		}
		for (int i = index; i < 81; i++) {
			int x = i / 9;
			int y = i % 9;
			if (board[x][y] == '.') {
				for (int j = 1; j < 10; j++) {
                    // 这个比用set找要快多了！！！！ 就是这里不一样
					if (!row[x][j - 1] && !col[y][j - 1] &&
						!cube[x / 3][y / 3][j - 1]) {
						board[x][y] = j + 48;
						row[x][j - 1] = true;
						col[y][j - 1] = true;
						cube[x / 3][y / 3][j - 1] = true;
						n--;
                        // 这里要从index进去，不用重复之前的
						if (DFS(i + 1, n, board))
							return true;

						board[x][y] = '.';
						row[x][j - 1] = false;
						col[y][j - 1] = false;
						cube[x / 3][y / 3][j - 1] = false;
						n++;		
					}
				}
				return false;
			}
		}
		return false;
	}
};

int main() {
    Solution s;
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
  s.solveSudoku(board);
}