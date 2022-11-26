//{ Driver Code Starts
// Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template in C++

class Solution 
{
    public:
    bool isPossible(int barrier,int arr[],int n,int student){
        int allocatedst = 1;
        int pages = 0;
        for(int i = 0 ; i < n ; i++){
            if(arr[i] > barrier)return false;
            if(pages + arr[i] > barrier){
                allocatedst++;
                pages = arr[i];
                if(allocatedst > student)return false;
            }else{
                pages+= arr[i];
            }
        }
        return true;
    }
    //Function to find minimum number of pages.
    int findPages(int A[], int N, int M) 
    {
        if(N < M){
            return -1;
        }
        int low = *min_element(A,A+N);
        int init = 0;
        int high = accumulate(A,A+N,init);
        int ans = 0;
        while(low <=  high){
            int mid = (low+high) >> 1;
            if(isPossible(mid,A,N,M)){
                ans = mid;
                high = mid - 1;
            }else{
                low = mid + 1;
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int A[n];
        for(int i=0;i<n;i++){
            cin>>A[i];
        }
        int m;
        cin>>m;
        Solution ob;
        cout << ob.findPages(A, n, m) << endl;
    }
    return 0;
}

// } Driver Code Ends