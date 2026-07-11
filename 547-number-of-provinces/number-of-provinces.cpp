class Solution {
private:
    // DFS to visit all cities connected to the current city
    void dfs(int node, vector<vector<int>>& isConnected, vector<int>& vis) {
        // Mark current city as visited
        vis[node] = 1;
        // Check all possible neighboring cities
        for (int j = 0; j < isConnected.size(); j++) {
            // If there is a connection and the city is not visited
            if (isConnected[node][j] && !vis[j]) {
                // Visit the connected city
                dfs(j, isConnected, vis);
            }
        }
    }

public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        // Keeps track of visited cities
        vector<int> vis(n, 0);
        // Stores the number of provinces
        int provinces = 0;
        // Traverse every city
        for (int i = 0; i < n; i++) {
            // If the city hasn't been visited,
            // it belongs to a new province
            if (!vis[i]) {
                provinces++;
                // Visit all cities in this province
                dfs(i, isConnected, vis);
            }
        }
        return provinces;
    }
};