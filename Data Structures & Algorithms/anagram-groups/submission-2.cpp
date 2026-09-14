class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> hashmap;
        for(string s : strs){
            vector<int> count(26, 0);
            for(char a : s){
                count[a-'a']++;
            }
            string key = to_string(count[0]);
            for(int i = 1; i<count.size(); i++){
                key += ',' + to_string(count[i]);
            }
            hashmap[key].push_back(s);
        }
        vector<vector<string>> result;
        for(pair p : hashmap){
            result.push_back(p.second);
        }
        return result;
    }
};
