class Solution {
public:
    void solve(vector<vector<char>> &board) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        if (!board.size()) return;
        int row = board.size();
        int col = board[0].size();
        vector<int> _row;
        vector<int> _col;
        //search the eadge to find 'O' to start BFS
        for (int i = 0; i < row; i++) {
            if (board[i][0] == 'O') {
                _row.push_back(i);
                _col.push_back(0);
            }
            if (board[i][col - 1] == 'O') {
                _row.push_back(i);
                _col.push_back(col - 1);
            }
        }
        
        for (int j = 0; j < col; j++) {
            if (board[0][j] == 'O') {
                _row.push_back(0);
                _col.push_back(j);
            }
            
            if (board[row - 1][j] == 'O') {
                _row.push_back(row - 1);
                _col.push_back(j);
            }
        }
        //BFS from each 'O' point on the edge.
        int k = 0;
        while (k < _row.size()) {
            int x = _row[k];
            int y = _col[k];
            board[x][y] = 'Y';
            
            if (x - 1 >= 0 && board[x - 1][y] == 'O') {
                _row.push_back(x - 1);
                _col.push_back(y);
            }
            if (y - 1 >= 0 && board[x][y - 1] == 'O') {
                _row.push_back(x);
                _col.push_back(y - 1);
            }
            if (x + 1 < row && board[x + 1][y] == 'O') {
                _row.push_back(x + 1);
                _col.push_back(y);
            }
            if (y + 1 < col && board[x][y + 1] == 'O') {
                _row.push_back(x);
                _col.push_back(y + 1);
            }
            k++;
            
        }
        
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                if (board[i][j] == 'O')
                    board[i][j] = 'X';
                if (board[i][j] == 'Y')
                    board[i][j] = 'O';
            }
        }
        
    }
  
};