//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
//User function template for C++
class Solution{
public:
    long long maxProductsolve(vector<int>& nums) {
        long long maxl = nums[0];
        long long maxr = nums[nums.size()-1];
        long long p = 1;
        bool zero = false;
        for(auto i : nums){
            p*= i;
            if(i == 0){
                p = 1;
                zero = true;
                continue;
            }
            maxl = max(maxl,p);
        }
        p = 1;
        for(int i = nums.size() -1 ; i >= 0 ; i--){
            p*= nums[i];
            if(nums[i] == 0){
                p = 1;
                zero = true;
                continue;
            }
            maxr = max(maxr,p);
        }
        // if(zero) return max(max(maxl,maxr),0);
        return max(maxl,maxr);
    }
	// Function to find maximum product subarray
	long long maxProduct(vector<int> arr, int n) {
	    return maxProductsolve(arr);
	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        vector<int> arr(n);
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.maxProduct(arr, n);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends