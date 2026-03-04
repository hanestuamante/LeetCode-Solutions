class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        
        vector<int> rowCount(m, 0);
        vector<int> colCount(n, 0);
        
        // Step 1: Pre-calculate sums for each row and column
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (mat[i][j] == 1) {
                    rowCount[i]++;
                    colCount[j]++;
                }
            }
        }
        
        int specialCount = 0;
        
        // Step 2: Check each '1' to see if its row and column sums are exactly 1
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (mat[i][j] == 1) {
                    if (rowCount[i] == 1 && colCount[j] == 1) {
                        specialCount++;
                    }
                }
            }
        }
        
        return specialCount;
    }
};