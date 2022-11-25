//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    bool check(int mid,vector<int> piles,int H){
        int Time = 0;
        for(int i = 0; i < piles.size(); i++){
            if((piles[i] % mid) != 0){
                Time += (piles[i]/mid)+1;
            }else{
                Time += (piles[i]/mid);
            }
        }
        if(Time <= H)return true;
        return false;
    }
    int Solve(int N, vector<int>& piles, int H) {
        int s = 1;
        int e = *max_element(piles.begin(),piles.end());
        while(s < e){
            int mid = s+(e-s)/2;
            if(check(mid,piles,H) == true){
                e = mid;
            }else{
                s = mid + 1;
            }
        }
        return e;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a;
        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            a.push_back(x);
        }
        int h;
        cin >> h;
        Solution obj;

        cout << obj.Solve(n, a, h);
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends