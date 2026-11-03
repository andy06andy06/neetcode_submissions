class Solution {
    bool dfs(vector<vector<int>>& adj, unordered_set<int>& hashset, int node, int parent){
        if(hashset.count(node)) return false;
        hashset.insert(node);
        for(int n : adj[node]){
            if(n==parent) continue;
            if(!dfs(adj, hashset, n, node)) return false;
        }
        return true;
    }
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        vector<vector<int>> adj(edges.size()+1);
        vector<int> res(2);
        for(vector<int> edge : edges){
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
            unordered_set<int> hashset;
            if(!dfs(adj, hashset, edge[0], 0)) {
                res = edge;
                break;
            }
            cout<<"("<<res[0]<<","<<res[1]<<")"<<endl;
        }

        return res;
    }
};
