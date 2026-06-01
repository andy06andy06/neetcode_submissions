class Solution {
public:
    int dfs(vector<vector<int>> &adjs, int i, unordered_set<int> &path, unordered_set<int> &visited, vector<int> &res){
        if(path.count(i)) return -1;
        if(visited.count(i)) return i;
        path.insert(i);
        for(int adj : adjs[i]){
            if(dfs(adjs, adj, path, visited, res)==-1) return -1;
        }
        path.erase(i);
        visited.insert(i);
        res.push_back(i);
        return i;
    }

    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adjs(numCourses);
        for(vector<int> pre : prerequisites){
            adjs[pre[1]].push_back(pre[0]);
        }
        unordered_set<int> path;
        unordered_set<int> visited;
        vector<int> res;
        for(int i = 0; i<adjs.size(); i++){
            if(dfs(adjs, i, path, visited, res)==-1) return {};
            
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
