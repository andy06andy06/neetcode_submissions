class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> merged;
        sort(intervals.begin(), intervals.end());
        merged.push_back(intervals[0]);
        for(int i = 1; i<intervals.size(); i++){
            vector<int> top = merged.back();
            vector<int> curr = intervals[i];
            if(curr[0] <= top[1]){
                merged.pop_back();
                merged.push_back({top[0], max(top[1], curr[1])});
            }else{
                merged.push_back(curr);
            }
        }
        return merged;
    }
};
