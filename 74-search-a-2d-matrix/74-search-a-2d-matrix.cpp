class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rows = matrix.size();
        int cols = matrix[0].size();
        int start = 0;
        int end = rows*cols-1;         
        while(start<=end){
            int mid = start+(end-start)/2; 
            int element = matrix[mid/cols][mid%cols];
            if(element==target){
                return 1;   
            }    
            if(element < target){
                start = mid + 1;
            }else{
                end = mid - 1;
            }
        }
        return 0;
    }
}; 