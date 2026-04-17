class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<double> stk;
        vector<pair<int, int>> cars(position.size());
        for(int i=0; i<position.size(); i++){
            cars[i] = {position[i], speed[i]};
        }
        sort(cars.rbegin(), cars.rend());
        for(auto& c: cars){
            stk.push_back((double)(target - c.first) / c.second);
            if(stk.size() >= 2 && stk.back() <= stk[stk.size()-2]){
                stk.pop_back();
            }
        }
        return stk.size();
    }
};
