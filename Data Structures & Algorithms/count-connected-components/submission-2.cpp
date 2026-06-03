class Solution {
public:
    void dfs(vector<vector<int>> &adjs, unordered_set<int> &hashset, unordered_set<int> &visited, int i){
        if(hashset.count(i)) return;
        if(visited.count(i)) return;
        hashset.insert(i);
        visited.insert(i);
        for(int adj : adjs[i]){
            dfs(adjs, hashset, visited, adj);
        }
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
            if(!hashset.count(i)){
                dfs(adjs, hashset, visited, i);  
                count++;
            }
        }
        return count;
    }
};
