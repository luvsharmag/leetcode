class Solution {
    public void setZeroes(int[][] matrix) {
        int rows = matrix.length;
        int cols = matrix[0].length;
        
        int arr1[] = new int[rows];
        int arr2[] = new int[cols];
        
        Arrays.fill(arr1,-1);
        Arrays.fill(arr2,-1);
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
}