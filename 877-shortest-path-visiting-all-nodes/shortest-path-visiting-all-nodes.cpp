class Solution {
public:
    int shortestPathLength(vector<vector<int>>& graph) {

        int n = graph.size();
        int finalMask = (1 << n) - 1;
        // {current node, visited mask}
        queue<pair<int, int>> q;
        // Same node different mask ke saath aa sakta hai
        vector<vector<int>> vis(n, vector<int>(1 << n, 0));
        for (int i = 0; i < n; i++) {
            int mask = (1 << i);
            q.push({i, mask});
            vis[i][mask] = 1;
        }
        int steps = 0;
        while (!q.empty()) {
            int sz = q.size();
            while (sz--) {
                auto [node, mask] = q.front();
                q.pop();
                if (mask == finalMask)
                    return steps;
                // Neighbours explore karo
                for (int neigh : graph[node]) {
                    int newMask = mask | (1 << neigh);
                    if (!vis[neigh][newMask]) {
                        vis[neigh][newMask] = 1;
                        q.push({neigh, newMask});
                    }
                }
            }
            steps++;
        }

        return -1;
    }
};