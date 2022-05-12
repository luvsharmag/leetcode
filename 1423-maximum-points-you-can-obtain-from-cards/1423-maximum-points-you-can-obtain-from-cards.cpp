class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        int s = 0;
        int e = k;
        int ans = 0;
        int s_sum = 0;
        int e_sum = 0;
        int c = 0;
        for(int i = n-1;c<k;i--,c++)
            e_sum +=cardPoints[i];
        while(e!=-1){
            ans = max(ans,s_sum+e_sum);
            s_sum+=cardPoints[s];
            if(n-e<n)
            e_sum-=cardPoints[n-e];
            s++;
            e--;
            
        }
        return ans;            
    }
};