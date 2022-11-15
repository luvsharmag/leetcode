//{ Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 


// } Driver Code Ends
class Solution{
    public:
        // void insertionsort(long long arr2[] , int m){
        //     int j = 0;
        //     int k = 0;
        //     for(int i = 1 ; i < m ; i++){
        //         j = i-1;
        //         k = arr2[i];
        //         while(j >= 0 && arr2[j] > k){
        //             arr2[j+1] = arr2[j];
        //             j-=1;
        //         }
        //         arr2[j+1] = k;
        //     }
        // }
        //Function to merge the arrays.
        void merge(long long arr1[], long long arr2[], int n, int m) 
        { 
            // int i = 0;
            // int j = 0;
            // while(i < n){
            //     if(arr1[i] > arr2[j]){
            //         swap(arr1[i],arr2[j]);
            //         insertionsort(arr2,m);
            //     }
            //     i+=1;
            // }
            //2nd apr
            int gap = ceil((float)(n+m)/2);
            while(gap > 0){
                int  i = 0;
                int  j = gap;
                while( j < (n+m)){
                    if(j < n && arr1[i] > arr1[j]){
                        swap(arr1[i],arr1[j]);
                    }else if(j >= n && i < n && arr1[i] > arr2[j-n]){
                        swap(arr1[i],arr2[j-n]);
                    }else if(j >= n && i >= n && arr2[i - n] > arr2[j - n]){
                        swap(arr2[i - n],arr2[j-n]);
                    }
                    i++;
                    j++;
                }
                if(gap == 1){
                    gap = 0;
                }else{
                    gap = ceil((float)gap/2);
                }
            }
        } 
};

//{ Driver Code Starts.

int main() 
{ 
	
	int T;
	cin >> T;
	
	while(T--){
	    int n, m;
	    cin >> n >> m;
	    
	    long long arr1[n], arr2[m];
	    
	    for(int i = 0;i<n;i++){
	        cin >> arr1[i];
	    }
	    
	    for(int i = 0;i<m;i++){
	        cin >> arr2[i];
	    }
	    Solution ob;
	    ob.merge(arr1, arr2, n, m); 

        for (int i = 0; i < n; i++) 
            cout<<arr1[i]<<" "; 
        
       
	    for (int i = 0; i < m; i++) 
		    cout<<arr2[i]<<" "; 
	    
	    cout<<endl;
	}

	return 0; 
} 

// } Driver Code Ends