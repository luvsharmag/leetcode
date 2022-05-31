class Solution {
public:
    string interpret(string command) {
        string ans = "";
        int n = command.length();
        int i = 0;
        while(i < n){
            char c = command[i];
            if(c=='G'){
                ans.push_back('G');
                i++;
            }else if(c == '('&& command[i+1] == ')'){
                ans.push_back('o');
                i+=2;
            }else{
                ans.push_back('a');
                ans.push_back('l');
                i+=4;
            }
        }
        return ans;
    }
};