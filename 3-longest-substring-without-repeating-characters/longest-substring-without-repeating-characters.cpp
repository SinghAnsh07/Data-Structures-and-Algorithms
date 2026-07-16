class Solution {
public:
    int lengthOfLongestSubstring(string s) {

        int last[128];
        // Sabko -1 se initialize karo
        memset(last, -1, sizeof(last));
        int left = 0;
        int ans = 0;

        // Window expand karo
        for (int right = 0; right < s.size(); right++) {

            // Agar character current window me pehle se hai
            if (last[s[right]] >= left) {
                left = last[s[right]] + 1;
            }

            // Current index store karo
            last[s[right]] = right;

            // Maximum length update karo
            ans = max(ans, right - left + 1);
        }

        return ans;
    }
};