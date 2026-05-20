class Solution {
   public:
    int rob(vector<int>& nums) {
        if (nums.size() == 1) {
            return nums[0];
        }else if(nums.size()==2){
            return max(nums[0], nums[1]);
        }
        int prev1 = nums[0];
        int prev2 = max(nums[0], nums[1]);
        for (int i = 2; i < nums.size(); i++) {
            prev1 = prev1 + nums[i];
            int now = max(prev1, prev2);
            prev1 = prev2;
            prev2 = now;
        }
        return prev2;
    }
};
