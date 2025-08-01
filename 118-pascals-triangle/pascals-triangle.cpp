class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> result; // Initialize the result vector to hold all rows of Pascal's Triangle
        
        // Loop through each row index from 0 to numRows - 1
        for(int i = 0; i < numRows; ++i) {
            // Create a new row with (i+1) elements, all initialized to 1
            vector<int> row(i + 1, 1);
            
            // Fill in the internal elements of the row (except the first and last, which are already 1)
            for(int j = 1; j < i; ++j) {
                // Each internal element is the sum of the two elements above it in the previous row
                row[j] = result[i - 1][j - 1] + result[i - 1][j];
            }
            
            // Add the completed row to the result vector
            result.push_back(row);
        }
        
        // Return the full Pascal's Triangle up to the specified number of rows
        return result;
    }
};