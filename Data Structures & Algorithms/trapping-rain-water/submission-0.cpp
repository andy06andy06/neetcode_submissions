class Solution {
public:
    int trap(vector<int>& height) {
        if(height.empty()) return 0;
        int l = 0; int r = height.size()-1;
        int leftMax = height[l], rightMax = height[r];
        int result = 0;
        while(r > l){
            if(rightMax > leftMax){
                l++;
                leftMax = max(leftMax, height[l]);
                result = result + (leftMax - height[l]);
            }
            else{
                r--;
                rightMax = max(rightMax, height[r]);
                result = result + (rightMax - height[r]);
            }
        }
        return result;
    }
};
