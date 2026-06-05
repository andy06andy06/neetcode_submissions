class Solution {
public:
    void dfs(vector<int>& candidates, vector<vector<int>> &res, vector<int> &ans, int target, int i, int sum){
        if(sum==target){
            res.push_back(ans);
            return;
        }
        if(sum > target) return;
        for(int j = i; j<candidates.size(); j++){
            if(j>i && candidates[j]==candidates[j-1]) continue;
            ans.push_back(candidates[j]);
            dfs(candidates, res, ans, target, j+1, sum+candidates[j]);
            ans.pop_back();
        }
    }
    
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> ans;
        sort(candidates.begin(), candidates.end());
        dfs(candidates, res, ans, target, 0, 0);
        return res;
    }
};
