//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
    public:
    void reverse(int s,int e,string &str){
        while(s <= e){
            swap(str[s++],str[e--]);
        }
    }
    //Function to reverse words in a given string.
    string reverseWords(string s) 
    { 
        int n = s.length();
        int i = 0, j = 0;
        while(j < n){
            if(s[j] == '.'){
                if(i == 0){
                    reverse(i,j-1,s);
                }else{
                    reverse(i+1,j-1,s);
                }
                i = j;
            }
            j++;
        }
        if(i != 0){
            reverse(i+1,j-1,s);
            reverse(0,n-1,s);
        }
        return s;
    } 
};

//{ Driver Code Starts.
int main() 
{
    int t;
    cin >> t;
    while (t--) 
    {
        string s;
        cin >> s;
        Solution obj;
        cout<<obj.reverseWords(s)<<endl;
    }
}
// } Driver Code Ends