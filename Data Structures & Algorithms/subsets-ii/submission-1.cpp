class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> temp;
        sort(nums.begin(), nums.end());
        dfs(res, temp, nums, 0);
        return res;
    }

    void dfs(vector<vector<int>> &res, vector<int> &temp, vector<int> &nums, int i){
        if(i==nums.size()){
            res.push_back(temp);
            return;
        }
        temp.push_back(nums[i]);
        dfs(res, temp, nums, i+1);
        temp.pop_back();
        while(i+1<nums.size() && nums[i]==nums[i+1]) {
            i++;
        }
        dfs(res, temp, nums, i+1);
    }
};
