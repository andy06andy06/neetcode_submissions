class Solution {
   public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int, int>> q;
        int fresh_orange = 0;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == 2) q.push({i, j});
                else if (grid[i][j] == 1) fresh_orange++;
            }
        }
        if(fresh_orange==0) return 0;
        int time = 0;
        vector<vector<int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        while (!q.empty()) {
            bool isInfected = false;
            int queue_size = q.size();
            for (int i = 0; i < queue_size; i++) {
                pair cur = q.front();
                q.pop();
                for (vector<int> direction : directions) {
                    int nx = cur.first + direction[0];
                    int ny = cur.second + direction[1];
                    if (nx >= 0 && nx < grid.size() && ny >= 0 && ny < grid[0].size() &&
                        grid[nx][ny] == 1) {
                        grid[nx][ny] = 2;
                        fresh_orange--;
                        q.push({nx, ny});
                        isInfected = true;
                    }
                }
            }
            if(isInfected) time++;
        }
        return fresh_orange==0 ? time : -1;
    }
};
