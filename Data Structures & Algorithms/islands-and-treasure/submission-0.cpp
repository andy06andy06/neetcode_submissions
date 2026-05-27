class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        queue<pair<int, int>> q;
        vector<vector<int>> directions = {{1,0}, {-1,0}, {0,1}, {0,-1}};
        for(int i = 0; i<grid.size(); i++){
            for(int j = 0; j<grid[0].size(); j++){
                if(grid[i][j]==0) q.push({i, j});
            }
        }
        while(!q.empty()){
            pair temp = q.front();
            q.pop();
            for(vector direction : directions){
                int nx = temp.first + direction[0];
                int ny = temp.second + direction[1];
                if(nx>=0 && nx<grid.size() && ny>=0 && ny<grid[0].size() && grid[nx][ny]==2147483647){
                    grid[nx][ny] = grid[temp.first][temp.second] + 1;
                    q.push({nx, ny});
                }
            }
        }
    }
};
