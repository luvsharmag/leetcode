//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
public:
    int findpivot(int arr[],int s,int e){
        if(s > e){
            return -1;
        }
        if(s==e)return s;
        int mid = (s+e) >> 1;
        if(mid < e&& arr[mid] > arr[mid+1]){
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
    int findMin(int arr[], int n){
        int pivot = findpivot(arr,0,n-1);
        return arr[pivot+1];
    }
};

//{ Driver Code Starts.


int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int i,a[n];
		for(i=0;i<n;i++)
		{
			cin>>a[i];
		}
		Solution ob;
		cout<<ob.findMin(a, n)<<endl;
	}
	return 0;
}
// } Driver Code Ends