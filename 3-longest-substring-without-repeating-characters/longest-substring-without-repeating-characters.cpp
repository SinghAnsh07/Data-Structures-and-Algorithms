class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> st;
        int left =0, ans =0;
        int n = s.size();

        for(int i=0; i< n; i++){
            while(st.count(s[i])){
                st.erase(s[left]);
                left++;
            }

            st.insert(s[i]);

            ans =  max(ans, i - left + 1);
        }

        return ans;
    }
};