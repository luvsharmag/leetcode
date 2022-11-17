//{ Driver Code Starts

#include<bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	/* if x is present in arr[] then returns the count
		of occurrences of x, otherwise returns 0. */
// 	int start(int arr[],int n,int x){
//         int s= 0,e = n -1;
//         int ans = -1;
//         while(s <= e){
//             int mid = s+(e-s)/2;
//             if(arr[mid] > x){
//                 e = mid-1;
//             }else if(arr[mid] < x){
//                 s = mid+1;
//             }else{
//                 ans = mid;
//                 e = mid - 1;
//             }
//         }
//         return ans;
//     }
//     int end(int arr[],int n,int x){
//         int s= 0,e = n -1;
//         int ans = -1;
//         while(s <= e){
//             int mid = s+(e-s)/2;
//             if(arr[mid] > x){
//                 e = mid-1;
//             }else if(arr[mid] < x){
//                 s = mid+1;
//             }else{
//                 ans = mid;
//                 s = mid+1;
//             }
//         }
//         return ans;
//     }
//     vector<int> find(int arr[], int n , int x )
//     {
//         vector<int> ans;
//         ans.push_back(start(arr,n,x));
//         ans.push_back(end(arr,n,x));
//         return ans;
//     }
	int count(int arr[], int n, int x) {
	   // vector<int> ans;
	   // ans = find(arr,n,x);
	   // if(ans[1]!= -1 && arr[0] != -1)
	   // return (ans[1] - ans[0]) + 1;
	   // return 0;
	   int first = lower_bound(arr,arr+n,x) - arr;
	   int last = upper_bound(arr,arr+n,x) - arr;
	   return last - first;
	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, x;
        cin >> n >> x;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.count(arr, n, x);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends