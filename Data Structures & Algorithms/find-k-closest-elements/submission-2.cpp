class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minheap;
        vector<int> res;
        for(int n : arr){
            int dist = abs(x - n);
            minheap.push({dist, n});
        }
        while(k>0){
            pair p = minheap.top();
            minheap.pop();
            res.push_back(p.second);
            k--;
        }
        sort(res.begin(), res.end());
        return res;
    }
};