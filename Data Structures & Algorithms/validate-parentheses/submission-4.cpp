class Solution {
public:
    bool isValid(string s) {
        stack<char> checker;
        for(char p : s){
            if(p=='(' || p=='[' || p=='{'){
                checker.push(p);
            } 
            else {
                if(p==')'){
                    if(checker.empty()) return false;
                    char right = checker.top();
                    if(right=='('){
                        checker.pop();
                        continue;
                    }
                    else return false;
                } 
                else if(p==']'){
                    if(checker.empty()) return false;
                    char right = checker.top();
                    if(right=='['){
                        checker.pop();
                        continue;
                    }
                    else return false;
                } 
                else if(p=='}'){
                    if(checker.empty()) return false;
                    char right = checker.top();
                    if(right=='{'){
                        checker.pop();
                        continue;
                    }
                    else return false;
                } 
            }
        }
        if(checker.empty()) return true;
        else return false;
    }
};
