//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution
{
public:
    int maxele(vector<int> arr,int n,int i){
        if(i == n-1){
            return arr[i];
        }
        int maxi = maxele(arr,n,i+1);
        return max(maxi,arr[i]);
    }
    int largest(vector<int> &arr, int n)
    {
        //apr1
        // priority_queue<int> pq;
        // for(int i = 0; i < n; i++){
        //     pq.push(arr[i]);
        // }
        // return pq.top();
        //apr2
        // int maxi = arr[0];
        // for(int i = 0; i < n; i++){
        //     if(maxi < arr[i]){
        //         maxi = arr[i];
        //     }
        // }
        // return maxi;
        //apr3
        return maxele(arr,n,0);
    }
};


//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int>arr(n);
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        Solution ob;
        cout << ob.largest(arr, n) << "\n";
    }
    return 0;
}

// } Driver Code Ends