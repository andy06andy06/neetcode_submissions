class Solution {
public:
    void dfs(vector<int> &nums, unordered_set<int> &hashset, vector<vector<int>> &res, vector<int> &temp){
        if(temp.size()==nums.size()){
            res.push_back(temp);
            return;
        }
        for(int j = 0; j<nums.size(); j++){
            if(hashset.count(nums[j])){
                continue;
            }
            hashset.insert(nums[j]);
            temp.push_back(nums[j]);
            dfs(nums, hashset, res, temp);
            hashset.erase(nums[j]);
            temp.pop_back();
        }
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
        unordered_set<int> hashset;
        vector<vector<int>> res;
        vector<int> temp;
        dfs(nums, hashset, res, temp);
        return res;
    }
};
