class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        priority_queue<pair<int, int>> maxheap;
        vector<int> res;
        for(int n : arr){
            int dist = abs(x - n);
            maxheap.push({dist, n});
            if(maxheap.size()>k){
                maxheap.pop();
            }
        }
        while(!maxheap.empty()){
            pair p = maxheap.top();
            maxheap.pop();
            res.push_back(p.second);
        }
        sort(res.begin(), res.end());
        return res;
    }
};