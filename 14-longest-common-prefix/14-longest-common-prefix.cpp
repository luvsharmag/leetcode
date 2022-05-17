class Solution {
public:
    string solve(string first,string second){
        string ans = "";
        int en = min(first.length(),second.length());
        for(int i = 0;i < en;i++){
            if(first[i]!=second[i]){
                break;  
            }
            ans+=first[i];
        }
        return ans;
    }
    string longestCommonPrefix(vector<string>& strs) {
        string prefix = strs[0];
        for(int i = 1; i < strs.size();i++){
            prefix = solve(prefix,strs[i]);
        }
        return prefix;
    }
};