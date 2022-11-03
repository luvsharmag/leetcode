//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++
class Solution{
public:
	void pushZerosToEnd(int arr[], int n) {
	    int i = 0, j = 0;
	    while(arr[i] != 0){
	        i++;
	        j++;
	    }
	    for(int k = i; k < n ; k++){
	        if(arr[k] > 0){
	            arr[j++] = arr[k];
	            arr[k] = 0;
	        }
	    }
	   // int temp[n];
	   // int j = 0;
	   // int cnt = 0;
	   // for(int i = 0 ; i  < n ; i++){
	   //     if(arr[i] > 0 ){
	   //         temp[j++] = arr[i];
	   //     }else{
	   //         cnt++;
	   //     }
	   // }
	   // while(cnt != 0){
	   //     temp[j++] = 0;
	   //     cnt--;
	   // }
	   // for(int i = 0 ; i < n; i++){
	   //     arr[i] = temp[i];
	   // }
	    
	}
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        int arr[n];
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        ob.pushZerosToEnd(arr, n);
        for (i = 0; i < n; i++) {
            cout << arr[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends