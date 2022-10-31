//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    int bsrec(int arr[],int n,int k,int s,int e){
        if(s <= e){
            int mid = s+(e-s)/2;
            if(arr[mid] < k){
                return bsrec(arr,n,k,mid+1,e);
            }else if(arr[mid] > k){
                return bsrec(arr,n,k,s,mid-1);
            }else{
                return mid;
            }
        }
        return -1;
    }
    int binarysearch(int arr[], int n, int k) {
        // int s = 0;
        // int e = n - 1;
        // while(s <= e){
        //     int mid = s + (e-s)/2;
        //     if(arr[mid] < k)s = mid+1;
        //     else if(arr[mid] > k)e = mid - 1;
        //     else return mid;
        // }
        // return -1;
        return bsrec(arr,n,k,0,n-1);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;

    while (t--) {
        int N;
        cin >> N;
        int arr[N];
        for (int i = 0; i < N; i++) cin >> arr[i];
        int key;
        cin >> key;
        Solution ob;
        int found = ob.binarysearch(arr, N, key);
        cout << found << endl;
    }
}

// } Driver Code Ends