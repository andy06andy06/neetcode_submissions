class Solution {
    bool dfs(vector<vector<int>>& adj, int node, unordered_set<int>& hashset, int parent
){
    if(hashset.count(node)) return false;
    hashset.insert(node);
    for(int n : adj[node]){
        if(n==parent) continue;
        if(!dfs(adj, n, hashset, node)) return false;
    }
    return true;
    }
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        for(vector<int> edge : edges){
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        unordered_set<int> hashset;
        if(!dfs(adj, 0, hashset, -1)) return false;
        
        return hashset.size()==n;
    }
};