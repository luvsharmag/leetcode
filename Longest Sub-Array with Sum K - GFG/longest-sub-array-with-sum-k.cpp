//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    int lenOfLongSubarr(int arr[],  int N, int K) 
    { 
        int sum =0 ;
        int maxl = 0;
        map<int,int> mp;
        for(int i =0 ; i < N; i++){
            sum += arr[i];
            if(sum == K){
                maxl = i+1;
            }
            if(mp.find(sum) == mp.end()){
                mp[sum] = i;
            }
            if(mp.find(sum - K) != mp.end()){
                if(maxl < (i - mp[sum - K])){
                    maxl = i - mp[sum - K];
                }
            }
        }
        return maxl;
    } 

};

//{ Driver Code Starts.

int main() {
	//code
	
	int t;cin>>t;
	while(t--)
	{
	    int n, k;
	    cin>> n >> k;
	    int a[n];
	    
	    for(int i=0;i<n;i++)
	        cin>>a[i];
	   Solution ob;
	   cout << ob.lenOfLongSubarr(a, n , k)<< endl;
	    
	}
	
	return 0;
}
// } Driver Code Ends