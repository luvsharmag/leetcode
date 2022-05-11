class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums){
        sort(nums.begin(),nums.end());
        int n = nums.size();
        vector<vector<int>> result;
        for(int i= 0;i<n;++i){
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }
            int j = i+1;
            int k = n -1;  
            int requiredSum = 0 - nums[i];
            while(j<k){  
            int sum = nums[j] + nums[k];         
            if(sum < requiredSum){
                ++j;
            }else if(sum > requiredSum){
                --k;
            }else{
                result.push_back(vector<int>{nums[i],nums[j],nums[k]});
                ++j;
                while(j < k && nums[j] == nums [j-1]){
                    ++j;
                }
            } 
            }
  
        }
    return result;
    }
};