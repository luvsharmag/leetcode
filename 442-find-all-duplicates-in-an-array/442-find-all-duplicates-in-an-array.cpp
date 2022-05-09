class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        int n = nums.size();
        int *freq = new int[n+1]();
        vector<int> vect;
        if(n==1)
            return vect;
        for(int i = 0;i < n;i++){
            if(freq[nums[i]]==0){
                freq[nums[i]] = 1;
            }else{
                vect.push_back(nums[i]);
            }
        }
        
        return vect;
    }
};