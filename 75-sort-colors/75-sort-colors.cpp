class Solution {
public:
    
        void swap(int *xp, int *yp) 
{ 
    int temp = *xp; 
    *xp = *yp; 
    *yp = temp; 
} 
  
void sortColors(vector<int>& nums) 
{ 
    int i, j, min_idx; 
  
    // One by one move boundary of unsorted subarray 
    for (i = 0; i < nums.size()-1; i++) 
    { 
        // Find the minimum element in unsorted array 
        min_idx = i; 
        for (j = i+1; j < nums.size(); j++) 
        if (nums[j] < nums[min_idx]) 
            min_idx = j; 
  
        // Swap the found minimum element with the first element 
        swap(&nums[min_idx], &nums[i]); 
    } 
} 
};