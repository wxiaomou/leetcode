class Solution {
public:
    bool solveSudoku(vector<vector<char> > &board) {
        unordered_set<int> hashset;
        for ( auto j = 0; j < 9; ++j ) {
            hashset.clear();
            for ( auto i = 0; i < 9; ++i ) {
                if (board[i][j] != '.') hashset.insert(board[i][j]);
            }
            for ( auto i = 0; i < 9; ++i ) {
                if (board[i][j] == '.') {
                    for ( auto k = 1; k <= 9; ++k ) {
                        if (hashset.count(k) > 0) continue;
                        board[i][j] = '0' + k;
                        if (isValidSudoku(board, i, j) && solveSudoku(board)) 
                            return true;
                        board[i][j] = '.';
                    }
                    return false;
                }
            }
        }
        return true;
    }
    
    bool isValidSudoku(vector<vector<char> > &board, int x, int y) {
        //row
        for ( auto i = 0; i < 9; ++i ) {
            if (i != x && board[i][y] == board[x][y])
                return false;
        }
        //col
        for ( auto j = 0; j < 9; ++j ) {
            if (j != y && board[x][j] == board[x][y])
                return false;
        }
        // for each sub
        for ( auto i = 3 * (x / 3); i < 3 * (x / 3 + 1); i++ ) {
            for ( auto j = 3 * (y / 3); j < 3 * (y / 3 + 1); j++ ) {
                if (i != x && j != y && board[x][y] == board[i][j])
                    return false;
            }
        } 
        return true;
    }
};