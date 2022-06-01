class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string merge = "";
        int len1 = word1.length();
        int len2 = word2.length();
        int i = 0,j = 0;
        while(i < len1 && j < len2){
            merge.push_back(word1[i]);
            merge.push_back(word2[j]);
            i++;
            j++;
        }
        if(i < len1)
            merge.append(word1,i,len1 - 1);
        if(j < len2)
            merge.append(word2,j,len2 - 1);
    
        return merge;
    }
};