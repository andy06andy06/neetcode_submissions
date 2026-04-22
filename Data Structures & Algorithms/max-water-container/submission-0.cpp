class Solution {
public:
    int maxArea(vector<int>& heights) {
        int result = 0; 
        int l = 0; int r = heights.size()-1;
        while(r > l){
            int area = (r - l) * min(heights[l], heights[r]);
            result = max(result, area);
            if(min(heights[l], heights[r])==heights[l]) l++;
            else if(min(heights[l], heights[r])==heights[r]) r--;
            else l++;
        }
        return result;
    }
};
