class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        vector<string> cur;
        dfs(res, s, cur, 0);
        return res;
    }

    void dfs(vector<vector<string>> &res, string s, vector<string> &cur, int j){
        if(j==s.length()) {
            res.push_back(cur);
            return;
        }

        for(int i = j; i<s.length(); i++){
            if(isPalindrome(s, j, i)){
                cur.push_back(s.substr(j, i-j+1));
                dfs(res, s, cur, i+1);
                cur.pop_back();
            }
        }
    }

    bool isPalindrome(string s, int left, int right){
        while(right>left){
            if(s[left]==s[right]){
                left++;
                right--;
            }else{
                return false;
            }
        }
        return true;
    }
};
