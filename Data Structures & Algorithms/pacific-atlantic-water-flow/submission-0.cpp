class Solution {
public:
    void dfs(vector<vector<int>>& heights, vector<vector<int>>& reachable, int i, int j){
        if(i<0 || i>heights.size()-1 || j<0 || j>heights[0].size()-1) return;
        reachable[i][j] = 1;

        if(i+1<heights.size() && heights[i+1][j]>=heights[i][j] && reachable[i+1][j]==0) dfs(heights, reachable, i+1, j);
        if(i-1>=0 && heights[i-1][j]>=heights[i][j] && reachable[i-1][j]==0) dfs(heights, reachable, i-1, j);
        if(j+1<heights[0].size() && heights[i][j+1]>=heights[i][j] && reachable[i][j+1]==0) dfs(heights, reachable, i, j+1);
        if(j-1>=0 && heights[i][j-1]>=heights[i][j] && reachable[i][j-1]==0) dfs(heights, reachable, i, j-1);
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        vector<vector<int>> pacific_reachable(heights.size(), vector<int>(heights[0].size(), 0));
        vector<vector<int>> atlantic_reachable(heights.size(), vector<int>(heights[0].size(), 0));
        
        for(int i = 0; i<heights.size(); i++){
            dfs(heights, pacific_reachable, i, 0);
            dfs(heights, atlantic_reachable, i, heights[0].size()-1);
        }
        for(int i = 0; i<heights[0].size(); i++){
            dfs(heights, pacific_reachable, 0, i);
            dfs(heights, atlantic_reachable, heights.size()-1, i);
        }
        vector<vector<int>> res;
        for(int i = 0; i<heights.size(); i++){
            for(int j = 0; j<heights[0].size(); j++){
                if(pacific_reachable[i][j]==1 && atlantic_reachable[i][j]==1) res.push_back({i, j});
            }
        }
        return res;
    }
};
