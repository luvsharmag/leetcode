//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
    int findpivot(int arr[],int s,int e){
        if(s > e)return -1;
        int mid = (s+e) >> 1;
        if(mid < e && arr[mid] > arr[mid+1]){
            return mid;
        }
        if(mid > s&& arr[mid] < arr[mid-1]){
            return mid-1;
        }
        if(arr[s] >= arr[mid]){
            return findpivot(arr,s,mid-1);
        }
        return findpivot(arr,mid+1,e);
    }
	int findKRotation(int arr[], int n) {
	    int pivot = findpivot(arr,0,n-1);
	    return pivot+1;
	}

};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        int a[n];
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.findKRotation(a, n);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends