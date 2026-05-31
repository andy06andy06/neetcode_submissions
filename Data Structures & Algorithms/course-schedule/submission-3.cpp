class Solution {
public:
    bool dfs(vector<vector<int>> &adjs, unordered_set<int> &path, int i){
        if(path.count(i)) return false;
        path.insert(i);
        for(int adj : adjs[i]){
            if(dfs(adjs, path, adj)==false) return false;
        }
        path.erase(i);
        adjs[i].clear();
        return true;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adjs(numCourses);
        for(vector<int> prerequisite : prerequisites){
            adjs[prerequisite[1]].push_back(prerequisite[0]);
        }
        for(int i = 0; i<adjs.size(); i++){
            unordered_set<int> path;
            
            if(dfs(adjs, path, i)==false) return false;
        }
        return true;
    }
};
