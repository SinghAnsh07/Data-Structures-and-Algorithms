class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        // Map each value to the list of its indices
        unordered_map<int, vector<int>> indexMap;

        for (int i = 0; i < nums.size(); i++) {
            indexMap[nums[i]].push_back(i);
        }

        int minDist = INT_MAX;

        for (auto& [val, indices] : indexMap) {
            // Need at least 3 occurrences
            if (indices.size() < 3) continue;

            // Indices are already in sorted order (we inserted left to right)
            // Check every consecutive triple (i, i+1, i+2)
            for (int i = 0; i + 2 < indices.size(); i++) {
                int dist = 2 * (indices[i + 2] - indices[i]);
                minDist = min(minDist, dist);
            }
        }

        return minDist == INT_MAX ? -1 : minDist;
    }
};