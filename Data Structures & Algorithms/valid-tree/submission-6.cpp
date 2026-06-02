class Solution {
public:
    bool dfs(vector<vector<int>> &adjs, unordered_set<int> &hashset, int i, int parent){
        if(hashset.count(i)) return false;
        hashset.insert(i);
        for(int adj : adjs[i]){
            if(adj==parent) continue;
            if(!dfs(adjs, hashset, adj, i)) return false;
        }
        
        return true;
    }
    
    bool validTree(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adjs(n);
        for(vector<int> edge : edges){
            adjs[edge[0]].push_back(edge[1]);
            adjs[edge[1]].push_back(edge[0]);
        }
        
        unordered_set<int> hashset;
        if(!dfs(adjs, hashset, 0, -1)) return false;
        
        return hashset.size()==n;
    }
};
