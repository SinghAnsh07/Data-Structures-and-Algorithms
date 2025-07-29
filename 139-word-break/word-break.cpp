class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        // Create a boolean vector 'dp' with size s.length() + 1
        // dp[i] will be true if s[0..i-1] can be segmented into dictionary words
        vector<bool> dp(s.size() + 1, false);
        
        // Empty string can always be segmented (base case)
        dp[0] = true;

        // Loop through the string from position 1 to the end
        for (int i = 1; i <= s.size(); i++) {
            // Check each word in the dictionary
            for (const string& w : wordDict) {
                int start = i - w.length(); // Calculate start position for comparison
                
                // Check if the start index is valid,
                // previous segment can be segmented (dp[start] == true),
                // and the substring matches the current word
                if (start >= 0 && dp[start] && s.substr(start, w.length()) == w) {
                    dp[i] = true; // Mark position i as reachable
                    break; // No need to check other words for this position
                }
            }
        }

        // Return whether the entire string can be segmented
        return dp[s.size()];
    }
};