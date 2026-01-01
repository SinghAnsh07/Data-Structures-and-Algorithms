class Solution {
public:
    // Recursive function to find minimum falling path sum
    // ending at cell (i, j)
    int f(int i, int j, vector<vector<int>> &matrix, vector<vector<int>> &dp){
        
        // If column index goes out of bounds, return a large value
        // so this path is never chosen in min()
        if(j < 0 || j >= matrix[0].size()) 
            return 1e9;

        // Base case: first row, path sum is the cell value itself
        if(i == 0) 
            return matrix[0][j];

        // If already computed, return stored result
        if(dp[i][j] != 1e9) 
            return dp[i][j];

        // Move straight up
        int up = matrix[i][j] + f(i - 1, j, matrix, dp);

        // Move diagonally left
        int leftDiag = matrix[i][j] + f(i - 1, j - 1, matrix, dp);

        // Move diagonally right
        int rightDiag = matrix[i][j] + f(i - 1, j + 1, matrix, dp);

        // Store and return the minimum of all three paths
        return dp[i][j] = min(up, min(leftDiag, rightDiag));
    }

    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();

        // DP table initialized with a large value (acts as "uncomputed")
        vector<vector<int>> dp(n, vector<int>(m, 1e9));

        int ans = 1e9;

        // Try all possible ending columns in the last row
        for(int j = 0; j < m; j++){
            ans = min(ans, f(n - 1, j, matrix, dp));
        }

        // Final answer: minimum falling path sum
        return ans;
    }
};
