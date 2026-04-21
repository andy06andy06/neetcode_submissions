class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        sort(nums.begin(), nums.end());
        for(int i = 0; i < nums.size()-2; i++){
            if (nums[i] > 0) break;
            if (i>0 && nums[i]==nums[i-1]) continue;

            int l = i+1; int r = nums.size()-1;
            int target = -nums[i];
            while(r > l){
                if(nums[r]+nums[l]>target){
                    r--;
                }
                else if(nums[r]+nums[l]<target){
                    l++;
                }
                else{
                    result.push_back({nums[i], nums[l], nums[r]});
                    l++; r--;
                    while(r>l && nums[l]==nums[l-1]) l++;
                    while(r>l && nums[r]==nums[r+1]) r--;
                }
            }
        }
        return result;
    }
};
