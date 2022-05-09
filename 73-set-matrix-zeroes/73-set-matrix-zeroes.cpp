class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int rows = matrix.size();
        int cols = matrix[0].size();
        
        int* arr1 = new int[rows];
        int* arr2 = new int[cols];
        
        *arr1 = {2};
        *arr2 = {2};
        for(int i = 0;i < rows; i++){
            for(int j = 0;j < cols; j++){
                if(matrix[i][j]==0){
                    arr1[i] = 0;
                    arr2[j] = 0;
                }
            }
        }
                                
        for(int i = 0;i < rows; i++){
            for(int j = 0;j < cols;j++){
                if(arr1[i]==0||arr2[j]==0){
                    matrix[i][j] = 0;
                }
            }
        }
    }
};