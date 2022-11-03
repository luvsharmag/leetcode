//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{   
public:
    void reverse(int s,int e,int arr[]){
        while( s < e){
            swap(arr[s],arr[e]);
            s++;
            e--;
        }
    }
    void leftRotate(int arr[], int n, int k) {
        reverse(0,k-1,arr);
        reverse(k,n-1,arr);
        reverse(0,n-1,arr);
        
        //left rotate
        // int temp[k];
        // for(int i = 0 ; i < k ; i++){
        //     temp[i] = arr[i];
        // }
        // for(int i = k; i < n; i++){
        //     arr[i - k] = arr[i];
        // }
        // for(int i = n- k; i < n; i++){
        //     arr[i] = temp[i - n + k];
        // }
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