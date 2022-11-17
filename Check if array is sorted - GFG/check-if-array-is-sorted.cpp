//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    bool issorted(int arr[],int n){
        if(n == 0||n == 1){
            return 1;
        }
        return arr[n-1] >= arr[n-2] && issorted(arr,n-1);
    }
    bool arraySortedOrNot(int arr[], int n) {
        // for(int i = 0; i < n-1 ; i++){
        //     if(arr[i] > arr[i+1]){
        //         return false;
        //     }
        // }
        // return true;
        return issorted(arr,n);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        bool ans = ob.arraySortedOrNot(arr, n);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends