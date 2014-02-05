#include <iostream>
#include <vector>
#include <string>

using namespace std;
class Solution {
public:
		bool **visit;
    bool exist(vector<vector<char> > &board, string word) {
			int m = board.size();
			int n = board[0].size();
			visit = new bool*[m];
			for (int i = 0; i < m; i++) visit[i] = new bool[n];
			for (int i = 0; i < m; i++) {
				for (int j = 0; j < n; j++) {
					visit[i][j] = false;
				}
			}
			
			for (int i = 0; i < m; i++) {
				for (int j = 0; j < n; j++) {
					if (find(board, i, j, word, 0, visit))
						return true;
					visit[i][j] = false;
				}
			}
			return false;
				
    }

		bool find(vector<vector<char> > &board, int row, int col, const string &word, int count, bool **visit) {
		//	cout << "row: " << row << "col: " << col << "count: " << count << endl;
				int m = board.size();
				int n = board[0].size();
				visit[row][col] = true;
				if (board[row][col] != word[count])
					return false;
				if (count == word.size() - 1)
					return true;

				bool left = false;
				bool right = false;
				bool up = false;
				bool down = false;

				if (col > 0 && !visit[row][col - 1]) {
					left = find(board, row, col - 1, word, count + 1, visit);
					visit[row][col - 1] = false;
				}
				if (left) return true;
				if (col < n - 1 && !visit[row][col + 1]) {
					right = find(board, row, col + 1, word, count + 1, visit);
					visit[row][col + 1] = false;
				}
				if (right) return true;
				if (row > 0 && !visit[row - 1][col]) {
					up = find(board, row - 1, col, word, count + 1, visit);
					visit[row - 1][col] = false;
				}
				if (up) return true;
				if (row < m - 1 && !visit[row + 1][col]) {
					down = find(board, row + 1, col, word, count + 1, visit);
					visit[row + 1][col] = false;
				}
				return left || right || up || down;
		}
};

int main(int argc, char **argv) {
	vector<char> tmp(1, 'a');
	tmp.push_back('b');
	vector<char> tmp1(1, 'c');
	tmp1.push_back('d');
	vector<vector<char> > text;
	text.push_back(tmp);
	text.push_back(tmp1);
	Solution sol;
	if(sol.exist(text, "acdb"))
		cout << "True\n";
	return 0;
}
