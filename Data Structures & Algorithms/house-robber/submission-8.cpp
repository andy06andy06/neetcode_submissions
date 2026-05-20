class Solution {
   public:
   vector<int> memo;
    int sol(vector<int>& nums, int i) {
        if (i==0) return nums[0];
        if (i==1) return max(nums[0], nums[1]);
        if(memo[i]!=-1){
            return memo[i];
        }
        memo[i] = max(nums[i]+sol(nums,i-2), sol(nums,i-1));
        return memo[i];
    }

    int rob(vector<int>& nums) {
        memo.resize(nums.size(), -1);
        return sol(nums,nums.size()-1);
    }
};
