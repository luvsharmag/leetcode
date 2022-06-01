class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        string str1 = "";
        string str2 = "";
        string temp1 = "";
        string temp2 = "";
        for(int i = 0; i < word1.size();i++){
            temp1 = word1[i];
            for(char c:temp1){
                str1.push_back(c);
            }
        }
        for(int i = 0; i < word2.size();i++){
            temp2 = word2[i];
            for(char c:temp2){
                str2.push_back(c);
            }
        }
        int k = str1.compare(str2);
        if(k==0){
            return true;
        }else{
            return false;
        }
    }
};