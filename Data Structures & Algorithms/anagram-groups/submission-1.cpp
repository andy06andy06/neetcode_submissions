class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> hashmap;
        for(const auto& s : strs) {
            vector<int> count(26,0);
            for(char a : s) {
                count[a-'a']++;
            }
    
        string key = to_string(count[0]);
        for(int i=1; i<26; i++){
            key += ','+to_string(count[i]);
        }
        hashmap[key].push_back(s);
        }
        vector<vector<string>> result;
        for (const auto& pair : hashmap){
            result.push_back(pair.second);
        }
        return result;
    }
};
