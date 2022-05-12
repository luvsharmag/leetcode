class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
      int n = nums.size();
    int count = 0,sum = 0;
    unordered_map <int,int> Map;
    Map[0] = 1;
    for (int i = 0; i < n; i++) 
    {
        sum += nums[i];
        if (Map.find(sum-k) != Map.end())
        count += Map[sum-k];
        Map[sum] = Map[sum] + 1;
    }
    return count;
    }
};