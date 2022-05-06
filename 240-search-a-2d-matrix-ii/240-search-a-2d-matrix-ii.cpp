class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rows = matrix.size();
        int col = matrix[0].size();
        
        int rowi = 0;
        int coli = col - 1;
        
        while(rowi < rows && coli >= 0 ){
            int element = matrix[rowi][coli];
            if(element== target){
                return 1;
            }
            if(element > target){
                coli--;
            }else{
                rowi++;
            }
        }
        return 0;
    }
};