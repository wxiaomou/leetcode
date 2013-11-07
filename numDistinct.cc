class Solution {
    public:
    int numDistinct(string S, string T) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        if ((S.length() < T.length()) ||
            (!S.length() || !T.length()))
        return 0;
        int **m = new int*[T.length()];
        for (int i = 0; i < T.length(); i++) m[i] = new int[S.length()];
        for (int i = 0; i < T.length(); i++) {
            for (int j = 0; j < S.length(); j++) {
                m[i][j] = -1;
            }
        }
        _find(S, T, 0, 0, m);
        if (m[0][0] > 0)
        return m[0][0];
        else
        return 0;
    }
    
    int _find(string &S, string &T, int j, int i, int **&m) {
        if (i == T.length()) {
            //m[i][j] = 1;
            return 1;//m[i][j];
        }
        if (j == S.length()) {
            return 0;
        }
        if (S.length() - j < T.length() - i) {
            m[i][j] = 0;
            return 0;
        }
        if (m[i][j] != -1) return m[i][j];
        int ret = 0;
        if (T[i] == S[j]) {
            ret += _find(S, T, j + 1, i + 1, m);
        }
        ret += _find(S, T, j + 1, i, m);
        m[i][j] = ret;
        return ret;
    }
};