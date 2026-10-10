class Solution {
public:
    unordered_map<char, vector<char>> hashmap;
    vector<string> letterCombinations(string digits) {
        if(digits=="") return {};
        hashmap['2'] = {'a', 'b', 'c'};
        hashmap['3'] = {'d', 'e', 'f'};
        hashmap['4'] = {'g', 'h', 'i'};
        hashmap['5'] = {'j', 'k', 'l'};
        hashmap['6'] = {'m', 'n', 'o'};
        hashmap['7'] = {'p', 'q', 'r', 's'};
        hashmap['8'] = {'t', 'u', 'v'};
        hashmap['9'] = {'w', 'x', 'y', 'z'};
        vector<string> res;
        backtracking(digits, res, 0, "");
        return res;
    }
    void backtracking(string digits, vector<string>& result, int index, string curr){
        if(index==digits.length()){
            result.push_back(curr);
            return;
        }
        vector<char> chars = hashmap[digits[index]];
        for(char c : chars){
            backtracking(digits, result, index+1, curr+c);
        }
    }
};
