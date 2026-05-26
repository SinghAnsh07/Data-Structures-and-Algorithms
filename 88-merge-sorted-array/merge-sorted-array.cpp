class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int> merged(m + n);

        for (int i = 0; i < m; i++) {
            merged[i] = nums1[i];
        }

        for (int i = 0; i < n; i++) {
            merged[m + i] = nums2[i];
        }

        sort(merged.begin(), merged.end());

        for (int i = 0; i < m + n; i++) {
            nums1[i] = merged[i];
        }
    }
};