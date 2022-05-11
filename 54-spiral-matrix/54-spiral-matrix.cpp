class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int rows = matrix.size();
        int cols = matrix[0].size();
        int startingrow = 0;
        int endingrow = rows-1;
        int startingcol = 0;
        int endingcol = cols-1;
        int total = rows*cols;
        int count = 0;
        vector<int> v;
        while(count<total){
            for(int i = startingcol;count<total&&i<=endingcol;i++){
                v.push_back(matrix[startingrow][i]);
                count++;
            }
            startingrow++;
            for(int i = startingrow;count<total&&i<=endingrow;i++){
                v.push_back(matrix[i][endingcol]);
                count++;
            }
            endingcol--;
            for(int i = endingcol;count<total&&i>=startingcol;i--){
                v.push_back(matrix[endingrow][i]);
                count++;
            }
            endingrow--;
            for(int i = endingrow;count<total&&i>=startingrow;i--){
                v.push_back(matrix[i][startingcol]);
                count++;
            }
            startingcol++;
        }
        return v;
    }
};