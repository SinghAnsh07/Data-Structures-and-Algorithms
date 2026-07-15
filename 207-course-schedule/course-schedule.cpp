class Solution {
private:
    bool checkcycle(int node, vector<vector<int>>& adj, vector<int>& vis, vector<int>& dfsvis){
        vis[node] = 1;
        dfsvis[node] = 1;
        for(auto it : adj[node]){
            if(!vis[it]){
                if(checkcycle(it, adj, vis, dfsvis)) return true;
            }else if(dfsvis[it]){
                return true;
            }
        }
        dfsvis[node] = 0;
        return false;
    }
public:
    bool canFinish(int V, vector<vector<int>>& edges) {
        vector<vector<int>> adj(V);
        for(auto &edge : edges){
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
        }
        vector<int> vis(V, 0);
        vector<int> pathvis(V, 0);
        for(int i=0; i<V; i++){
            if(!vis[i]){
                if(checkcycle(i, adj, vis, pathvis)){
                    return false;
                }
            }
        }
        return true;
    }
};