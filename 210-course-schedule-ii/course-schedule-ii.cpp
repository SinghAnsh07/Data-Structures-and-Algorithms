class Solution {
public:
    vector<int> findOrder(int n, vector<vector<int>> &prerequisites) {

        // Adjacency list
        vector<vector<int>> adj(n);

        // Stores indegree of each node
        vector<int> indegree(n, 0);

        // Build graph
        for (auto &edge : prerequisites) {
            int u = edge[0];
            int v = edge[1];

            // v -> u
            adj[v].push_back(u);
        }

        // Calculate indegree
        for (int i = 0; i < n; i++) {
            for (auto it : adj[i]) {
                indegree[it]++;
            }
        }

        queue<int> q;

        // Push all nodes with indegree 0
        for (int i = 0; i < n; i++) {
            if (indegree[i] == 0)
                q.push(i);
        }

        vector<int> topo;

        // Kahn's Algorithm
        while (!q.empty()) {

            int node = q.front();
            q.pop();

            topo.push_back(node);

            // Reduce indegree of neighbours
            for (auto it : adj[node]) {
                indegree[it]--;

                // If indegree becomes 0, push into queue
                if (indegree[it] == 0)
                    q.push(it);
            }
        }

        // Cycle exists
        if (topo.size() != n)
            return {};

        return topo;
    }
};