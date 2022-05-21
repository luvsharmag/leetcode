class Solution {
public:
    void helper(vector<string> &ans, int open, int close, string &s, int n){
        
        if(open==n && close==n){
            ans.push_back(s);
            return;
        }
        
        if(open < n){
            s.push_back('(');
            helper(ans, open+1, close,s, n);
            s.pop_back();
        }
        
        if(close < open){
            s.push_back(')');
            helper(ans, open, close+1, s, n);
            s.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string s = "";
        
        helper(ans, 0, 0, s, n);
        return ans;
    }
};