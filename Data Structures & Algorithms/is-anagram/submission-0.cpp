class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char, int> hashmap_s;
        unordered_map<char, int> hashmap_t;
        if(s.length() != t.length())
            return false;

        for(int i=0; i<s.length(); i++){
            hashmap_s[s[i]]++;
            hashmap_t[t[i]]++;
        }
        return hashmap_s == hashmap_t;
    }
};
