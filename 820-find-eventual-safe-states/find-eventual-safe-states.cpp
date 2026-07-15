class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& adj) {
        int V = adj.size();
        vector<vector<int>> adjrev(V);
        vector<int> indegree(V, 0);
        for(int i=0; i<V; i++){
            // change i to it
            //then it to i , reverse the nodes
            for(auto it : adj[i]){
                adjrev[it].push_back(i);
                indegree[i]++;
            }
        }

        queue<int> q;
        vector<int> safenodes;
        // safenode mein push krr do , indegree 0 hone ke baad
        for(int i =0; i<V; i++){
            if(indegree[i] == 0){
                q.push(i);
            }
        }

        while(!q.empty()){
            int node = q.front();
            q.pop();
            safenodes.push_back(node);
            for(auto it : adjrev[node]){
                indegree[it]--;
                if(indegree[it] == 0) q.push(it);
            }
        }

        sort(safenodes.begin(), safenodes.end());
        return safenodes;
    }
};