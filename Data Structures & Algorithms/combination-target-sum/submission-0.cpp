class Solution {
public:
    void dfsSum(vector<int>& nums, vector<vector<int>> &res, vector<int> &cur, int target, int i, int sum){
        if(sum==target){
            res.push_back(cur);
            return;
        }
        if(sum > target){
            return;
        }

        for(int j = i; j<nums.size(); j++){
            cur.push_back(nums[j]);
            dfsSum(nums, res, cur, target, j, sum+nums[j]);
            cur.pop_back();
        }
    }
    
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>> res;
        vector<int> cur;
        dfsSum(nums, res, cur, target, 0, 0);
        return res;
    }
};
