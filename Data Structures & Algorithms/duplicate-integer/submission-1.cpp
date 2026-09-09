class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_set<int> hashset;
        for(int num : nums){
            if(!hashset.count(num)){
                hashset.insert(num);
            }
            else
                return true;
        }
        return false;
    }
};