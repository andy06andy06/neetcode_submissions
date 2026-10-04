class Solution {
public:
    int missingNumber(vector<int>& nums) {
        unordered_set<int> num_set(nums.begin(), nums.end());
        for(int i = 0; i<nums.size(); i++){
            if(!num_set.count(i)){
                return i;
            }
        }
    }
};
