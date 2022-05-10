class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int l = 0;
        int r = n-1;
        int profit = 0;
        int *arr = new int[n]();
        int maxp = n - 1;
        for(int i = n-1;i >= 0;i--){
            if(prices[i] > prices[maxp]){
                maxp = i;
                *(arr+i) = prices[maxp];
            }else{
                *(arr+i) = prices[maxp];
            }
        }
        for(int i = 0;i < n; i++){
            profit = max((arr[i] - prices[i]),profit);
        }
        return profit;
    }
};