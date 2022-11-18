//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    void merge(int arr1[],int arr2[],int n,int m){
        
        int gap = ceil((float)(n+m)/2);
        while(gap > 0){
            int i = 0;
            int j = gap;
            while(j < (n+m)){
                if(j < n && arr1[i] > arr1[j]){
                    swap(arr1[i],arr1[j]);
                }else if(j >= n && i < n && arr1[i] > arr2[j-n]){
                    swap(arr1[i],arr2[j-n]);
                }else if(j >= n && i >= n && arr2[i-n] > arr2[j-n]){
                    swap(arr2[i-n],arr2[j-n]);
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
    int kthElement(int arr1[], int arr2[], int n, int m, int k)
    {
        merge(arr1,arr2,n,m);
        k-=1;
        if(k >= n){
            return arr2[k-n];
        }
        return arr1[k];
    }
};

//{ Driver Code Starts.
 
// Driver code
int main()
{
	int t;
	cin>>t;
	while(t--){
		int n,m,k;
		cin>>n>>m>>k;
		int arr1[n],arr2[m];
		for(int i=0;i<n;i++)
			cin>>arr1[i];
		for(int i=0;i<m;i++)
			cin>>arr2[i];
		
		Solution ob;
        cout << ob.kthElement(arr1, arr2, n, m, k)<<endl;
	}
    return 0;
}
// } Driver Code Ends