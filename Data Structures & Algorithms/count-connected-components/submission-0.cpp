class Solution {
public:
    void dfs(vector<vector<int>> &adjs, unordered_set<int> &hashset, unordered_set<int> &visited, int i, int parent){
        if(hashset.count(i)) return;
        if(visited.count(i)) return;
        hashset.insert(i);
        visited.insert(i);
        parent = i;
        for(int adj : adjs[i]){
            dfs(adjs, hashset, visited, adj, i);
        }
        hashset.erase(i);
    }
    
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adjs(n);
        for(vector<int> edge : edges){
            adjs[edge[0]].push_back(edge[1]);
            adjs[edge[1]].push_back(edge[0]);
        }
        unordered_set<int> hashset;
        unordered_set<int> visited;
        int count = 0;
        for(int i = 0; i<adjs.size(); i++){
            if(!visited.count(i)){
                dfs(adjs, hashset, visited, i, -1);  
                count++;
            }
        }
        return count;
    }
};
