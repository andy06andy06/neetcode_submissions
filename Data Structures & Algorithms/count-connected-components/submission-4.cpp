class Solution {
    void dfs(int node, vector<vector<int>>& adj, unordered_set<int>& hashset){
        if(hashset.count(node)){
            return;
        }
        hashset.insert(node);
        for(int n : adj[node]){
            dfs(n, adj, hashset);
        }
    }
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        for(vector<int> edge : edges){
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        unordered_set<int> hashset;
        int res = 0;
        for(int i = 0; i<n; i++){
            if(!hashset.count(i)){
                dfs(i, adj, hashset);
                res++;
            }
        }
        return res;
    }
};
