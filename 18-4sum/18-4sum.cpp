class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {       
        vector<vector<int>> result;
        if(nums.empty())
            return result;
        int n = nums.size();
        sort(nums.begin(),nums.end());
        int i,j;
        for(i = 0; i < n ;i++){            
            for(j = i+1; j < n; j++){
                int remainsum = target - nums[i] - nums[j];
                int l = j + 1;
                int r = n - 1;
                while(l<r){
                    int lrsum = nums[l] + nums[r];
                    if(lrsum < remainsum){
                        l++;
                    }   
                    else if(lrsum > remainsum){                     
                        r--;
                    }else{
                        result.push_back(vector<int> {nums[i],nums[j],nums[r],nums[l]});
                        while(l < r && nums[l] == nums[l+1]){
                            l++;
                        }
                        while(l < r && nums[r] == nums[r-1]){
                            r--;
                        }  
                        l++;
                        r--;
                    }                 
                    
                }
                while(j + 1 < n && nums[j+1] == nums[j]) ++j;
            }
            while(i + 1 < n && nums[i+1] == nums[i]) ++i;
        }
        return result;
    }
};