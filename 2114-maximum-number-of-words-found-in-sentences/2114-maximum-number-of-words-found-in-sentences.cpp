class Solution {
public:
    int mostWordsFound(vector<string>& sentences) {
        int n = sentences.size();
        int count = 1;
        int maxword = 0;
        int i = 0;
        while( i < n){
            string each = sentences[i];
            for(int j = 0;j < each.length();j++ ){
                if(each[j]==' '){
                    ++count;
                }
            }
            if(count >= maxword)
                maxword = count;
            count  = 1;
            i++;
        }
        return maxword;
    }
};