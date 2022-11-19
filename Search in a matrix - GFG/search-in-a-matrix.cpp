//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
    int binarysearch(vector<int> arr,int n,int k){
        int s = 0,e = n - 1;
        while(s <= e){
            int m = s+(e-s)/2;
            if(arr[m] == k)return 1;
            else if(arr[m] < k)s = m + 1;
            else e = m - 1;
        }
        return 0;
    }
	int matSearch (vector <vector <int>> &arr, int n, int m, int k)
	{
	    int low = 0;
	    int high = n -1;
	    while(low <= high){
	        
	        int mid = (low + high)/2;
	        if(k == arr[mid][0])return 1;
	        if(k == arr[mid][m-1])return 1;
	        if(k > arr[mid][0] && k < arr[mid][m-1]){
	            if(n % 2 != 0){
	                return binarysearch(arr[mid],m,k);
	            }else{
	                if(binarysearch(arr[mid],m,k)){
	                    return 1;
	                }
	                low = mid + 1;
	            }
	        }
	        if(k < arr[mid][0])high = mid -1;
	        if(k > arr[mid][m-1])low = mid + 1;
	    }
	    return 0;
	}
};

//{ Driver Code Starts.

int main ()
{
    int t; cin >> t;
    while (t--){
        int n, m; cin >> n >> m;
        vector <vector <int>> arr (n, vector <int> (m));
        for (int i=0;i<n;i++)
            for (int j=0;j<m;j++)
                cin >> arr[i][j];
                
        int x; cin >> x;
        Solution ob;
        cout << ob.matSearch (arr, n, m, x) << endl;
    }
}
// } Driver Code Ends