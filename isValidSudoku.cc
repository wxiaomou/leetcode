class Solution {
public:
    bool isValidSudoku(vector<vector<char> > &board) {
        unordered_set<int> hashset;
        // for each line;
        for ( auto i = 0; i < 9; ++i ) {
            hashset.clear();
            for (auto j = 0; j < 9; ++j) {
                if (board[i][j] != '.' && hashset.count(board[i][j]) > 0)
                    return false;
                hashset.insert(board[i][j]);
            }
        }
        // for each col
        for ( auto j = 0; j < 9; ++j ) {
            hashset.clear();
            for (auto i = 0; i < 9; ++i ) {
                if (board[i][j] != '.' && hashset.count(board[i][j]) > 0)
                    return false;
                hashset.insert(board[i][j]);
            }
        }
        // for each sub
        for ( auto i = 0; i < 9; i += 3 ) {
            for ( auto j = 0; j < 9; j += 3 ) {
                hashset.clear();
                for ( auto k1 = i; k1 < i + 3; k1++ ) {
                    for ( auto k2 = j; k2 < j + 3; k2++ ) {
                        if (board[k1][k2] != '.' && hashset.count(board[k1][k2]) > 0)
                            return false;
                        hashset.insert(board[k1][k2]);
                    }
                }
            }
        } 
        return true;
    }
};