class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        int jewel = 0;
        for(char ch: jewels){
            for(int i = 0; i < stones.length();i++){
                if(ch == stones[i]){
                    jewel++;
                    stones[i] = '$';                
                }
            }
        }
        return jewel;
    }
};