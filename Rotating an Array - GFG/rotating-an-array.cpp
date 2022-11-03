//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{   
public:
    void leftRotate(int arr[], int n, int k) {
        //left rotate
        int temp[k];
        for(int i = 0 ; i < k ; i++){
            temp[i] = arr[i];
        }
        for(int i = k; i < n; i++){
            arr[i - k] = arr[i];
        }
        for(int i = n- k; i < n; i++){
            arr[i] = temp[i - n + k];
        }
        //right rotate
        // if(n  == 0)return;
        // int temp[k];
        // for(int i = n - k; i < n; i++){
        //     temp[i-n+k] = arr[i];
        // }
        // for(int i = n - k - 1; i >= 0 ; i--){
        //     arr[i+k] = arr[i];
        // }
        // for(int i = 0; i < k ; i++){
        //     arr[i] = temp[i];
        // }
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, d;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        cin >> d;
        Solution ob;
        ob.leftRotate(arr, n, d);
        for (int i = 0; i < n; i++) {
            cout << arr[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}



// } Driver Code Ends