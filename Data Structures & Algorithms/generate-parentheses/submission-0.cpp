class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        int open = 0;
        int close = 0;

        parenthesis(open, close, "", res, n);
        return res;
    }

    void parenthesis(int open, int close, string s, vector<string> &res, int n){
        if(close > open) return;
        if(s.length()==2*n) {
            res.push_back(s);
            return;
        }
        if(open < n){
            s.push_back('(');
            parenthesis(open+1, close, s, res, n);
            s.pop_back();
        }
        if(open > close){
            s.push_back(')');
            parenthesis(open, close+1, s, res, n);
            s.pop_back();
        }
    }
};
