class Solution {
public:
    string removeKdigits(string num, int k) {
        string st;
        for(char d : num){
            while(!st.empty() && k > 0 && st.back() > d){
                st.pop_back();
                k--;
            }
            st.push_back(d);
        }
        while(k--) st.pop_back();
        int start = 0;
        while(start < (int) st.size() - 1 && st[start] == '0') start++;
        return st.empty() ? "0" : st.substr(start);
    }
};