
class Solution {
public:
    long long sumSubarrayMaxs(vector<int>& a){
        int n = a.size();
        vector<long long> L(n), R(n);
        stack<int> st;
        for(int i = 0; i < n; i++){
            while(!st.empty() && a[st.top()] < a[i]) st.pop();
            L[i] = st.empty() ? i+1 : i-st.top();
            st.push(i);
        }
        while(!st.empty()) st.pop();
        for(int i = n-1; i >= 0; i--){
            while(!st.empty() && a[st.top()] <= a[i]) st.pop();
            R[i] = st.empty() ? n-i : st.top()-i;
            st.push(i);
        }
        long long res = 0;
        for(int i = 0; i < n; i++) res += (long long)a[i]*L[i]*R[i];
        return res;
    }

    long long sumSubarrayMins(vector<int>& a){
        int n = a.size();
        vector<long long> L(n), R(n);
        stack<int> st;
        for(int i = 0; i < n; i++){
            while(!st.empty() && a[st.top()] > a[i]) st.pop();
            L[i] = st.empty() ? i+1 : i-st.top();
            st.push(i);
        }
        while(!st.empty()) st.pop();
        for(int i = n-1; i >= 0; i--){
            while(!st.empty() && a[st.top()] >= a[i]) st.pop();
            R[i] = st.empty() ? n-i : st.top()-i;
            st.push(i);
        }
        long long res = 0;
        for(int i = 0; i < n; i++) res += (long long)a[i]*L[i]*R[i];
        return res;
    }

    long long subArrayRanges(vector<int>& a){
        return sumSubarrayMaxs(a) - sumSubarrayMins(a);
    }
};