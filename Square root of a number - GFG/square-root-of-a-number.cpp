//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

  

// } Driver Code Ends
// Function to find square root
// x: element to find square root
class Solution{
  public:
    long long int sqroot(long long int x){
        int s = 0;
        int e = x;
        long long int ans = 0;
        long long int mid = s+(e-s)/2;
        while(s <= e){
            long long int square = mid * mid;
            if(square == x){
                return mid;
            }
            if(square < x){
                ans = mid;
                s = mid + 1;
            }else{
                e = mid - 1;
            }
            mid = s+(e-s)/2;
        }
        return ans;
    }
    double findPrecision(long long int num,long long int x){
        
        double fr = 1;
        double ans = num;
        for(int i = 0; i < 3; i++){
            fr = fr/10;
            for(double j = ans; j*j < x; j = j + fr){
                ans = j;
            }
        }
        return ans;
    }
    long long int floorSqrt(long long int x) 
    {
        long long int squareroot = sqroot(x);
        return squareroot;
        
    }
};

//{ Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		long long n;
		cin>>n;
		Solution obj;
		cout << obj.floorSqrt(n) << endl;
	}
    return 0;   
}

// } Driver Code Ends