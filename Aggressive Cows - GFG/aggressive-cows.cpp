//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
public:
    bool canplacecows(int dist,vector<int> &arr,int n,int cows){
        int coord = arr[0];
        int cnt = 1;
        for(int i = 1; i < n; i++){
            if(arr[i] - coord >= dist){
                coord = arr[i];
                cnt++;
            } 
            if(cnt == cows){
                return true;
            }
        }
        return false;
    }
    int solve(int n, int k, vector<int> &arr) {
        sort(arr.begin(),arr.end());
        int low = 1;
        int high = arr[n-1] - arr[0];
        
        int ans = 0;
        while(low <= high){
            int mid = (low+high) >>1;
            if(canplacecows(mid,arr,n,k)){
                ans = mid;
                low = mid+1;
            }else{
                high = mid -1;
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t = 1;
    cin >> t;

    // freopen ("output_gfg.txt", "w", stdout);

    while (t--) {
        // Input

        int n, k;
        cin >> n >> k;

        vector<int> stalls(n);
        for (int i = 0; i < n; i++) {
            cin >> stalls[i];
        }
        // char ch;
        // cin >> ch;

        Solution obj;
        cout << obj.solve(n, k, stalls) << endl;

        // cout << "~\n";
    }
    // fclose(stdout);

    return 0;
}
// } Driver Code Ends