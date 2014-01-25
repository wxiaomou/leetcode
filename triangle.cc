class Solution {
    public:
    int minimumTotal(vector<vector<int> > &triangle) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        vector<int> ref = triangle[triangle.size() - 1];
        if (triangle.size() == 0) return 0;
        for (int i = triangle.size() - 2; i >= 0; --i) {
            for (int j = 0; j < triangle[i].size(); j++) {
                ref[j] = triangle[i][j] + min(ref[j], ref[j + 1]);
            }
        }
        return ref[0];
    }   
};