//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


int KthMissingElement(int a[], int n, int k);


int main()
{
    int t;
    cin>>t;
    
    while(t--)
    {
        int n,k;
        cin>>n>>k;
        int a[n];
        for(int i=0;i<n;i++)
            cin>>a[i];
        
        cout << KthMissingElement(a, n, k) << endl;
    
    }
    return 0;
}

// } Driver Code Ends


int KthMissingElement(int a[], int n, int k)
{
    int maxi = INT_MIN;
    int mini= INT_MAX;
    unordered_map<int,int> mp;
    for(int i = 0; i < n; i++){
        mp[a[i]] = 1;
        maxi = max(maxi,a[i]);
        mini = min(mini,a[i]);
    }
    // cout<<maxi<<" "<<mini<<endl;
    int cnt = 0;
    for(int i = mini; i <= maxi; i++){
        if(mp[i] == 0)cnt+=1;

        if(cnt== k)return i;
    }
    return -1;
}