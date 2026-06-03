class Solution {
public:
    bool dfs(vector<vector<int>>& adjs, int i, unordered_set<int> &hashset, int parent){
        if(hashset.count(i)) return true;
        hashset.insert(i);

        for(int adj : adjs[i]){
            if(adj==parent) continue;
            if(dfs(adjs, adj, hashset, i)) return true;
        }
        return false;
    }
    
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        vector<vector<int>> adjs(edges.size()+1);

        for(vector<int> edge : edges){
            adjs[edge[0]].push_back(edge[1]);
            adjs[edge[1]].push_back(edge[0]);
            unordered_set<int> hashset;
            if(dfs(adjs, edge[0], hashset, -1)) return edge;
        }
        return {};
    }
};
