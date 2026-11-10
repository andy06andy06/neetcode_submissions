class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int l = 1; int r = *max_element(piles.begin(), piles.end());
        int rate = l;
        while(r >= l){
            long long time = 0;
            int mid = l+(r - l) / 2;
            for (int& banana : piles) time += ceil(static_cast<double>(banana)/mid);
            if (time > h){
                l = mid + 1;
            }
            else if (time <= h){
                rate = mid;
                r = mid-1;
            }
        }
        return rate;
    }
};
