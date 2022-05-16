class Solution {
public:
    int strStr(string haystack, string needle) {
        if(haystack.find(needle) < haystack.length()){
            return haystack.find(needle);
        }
        return -1;
    }
};