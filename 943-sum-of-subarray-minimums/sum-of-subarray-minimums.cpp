//for n elements, there are n * (n + 1) / 2 subarrays.  
// brute force - O(n^2) that is too slow


class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        const int MOD = 1e9 + 7;
        long long ans = 0;
        stack<int> st;

        for(int i=0; i<= n; i++){
            while(!st.empty() && (i == n || arr[st.top()] >= arr[i])){
                int mid = st.top(); st.pop();
                long long left = st.empty() ? mid + 1 : mid - st.top();
                long long right = i - mid;
                ans = (ans + (long long)arr[mid] * left % MOD * right) % MOD;
            }
            st.push(i);
        }
        return ans;
    }
};