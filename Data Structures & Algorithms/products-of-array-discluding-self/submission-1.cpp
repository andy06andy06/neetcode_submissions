class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> pre_product(nums.size());
        vector<int> suf_product(nums.size());
        vector<int> res(nums.size());
        int pre_res = 1, suf_res = 1;
        pre_product[0] = 1;
        suf_product[nums.size()-1] = 1;
        for(int i=1; i<nums.size(); i++){
            pre_res *= nums[i-1];
            pre_product[i] = pre_res;
        }
        for(int i=nums.size()-2; i>=0; i--){
            suf_res *= nums[i+1];
            suf_product[i] = suf_res; 
        }
        for(int i=0; i<nums.size(); i++){
            res[i] = pre_product[i]*suf_product[i];
        }
        return res;
    }
};
