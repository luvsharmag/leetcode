class Solution {
public:
    int compress(vector<char>& chars) {
        int ansindex  = 0;
        int n = chars.size();
        int i = 0;
        while(i<n){
            int j = i+1;
            while(j < n && chars[j]==chars[i]){
                j++;
            }
            
            chars[ansindex++] = chars[i];
            
            int count = j - i;
            
            if(count > 1){
                string cnt = to_string(count);
                for(char ch : cnt){
                    chars[ansindex++] = ch;
                }
            }
            i = j;
        }
        return ansindex;
    }
};