class Solution {
public:
    string intToRoman(int num) {
        vector<string> roman({"I","IV","V","IX","X","XL","L","XC","C","CD","D","CM","M"});
        vector<int> values({1,4,5,9,10,40,50,90,100,400,500,900,1000});
        string ans = "";
        int index = roman.size() - 1;
        while(num > 0){
            while(values[index]<=num){
                ans = ans + roman[index];
                num -= values[index];
            }
            index--;
        }
        return ans;
    }
};