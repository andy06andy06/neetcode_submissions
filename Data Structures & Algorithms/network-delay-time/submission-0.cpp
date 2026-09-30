class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int, int>>> adjs(n+1);
        for(auto& time : times){
            int u = time[0];
            int v = time[1];
            int w = time[2];

            adjs[u].push_back({v, w});
        }

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minheap;
        
        vector<int>dist(n+1, 1e9);
        dist[k] = 0;
        minheap.push({0, k});

        while(!minheap.empty()){
            pair<int, int> curr = minheap.top();
            minheap.pop();
            int dis = curr.first;
            int node = curr.second;
            if(dis > dist[node]) continue;
            for(auto& adj : adjs[node]){
                int target = adj.first;
                int time = adj.second;
                if(dis + time < dist[target]){
                    dist[target] = dis+time;
                    minheap.push({dist[target], target});
                }
            }
        }
        int ans = 0;
        for(int i = 1; i<=n; i++){
            if(dist[i]==1e9) return -1;
            ans = max(ans, dist[i]);
        }
        return ans;
    }
};
