//{ Driver Code Starts
#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;



/* Function to print an array */
void printArray(int arr[], int size)
{
    int i;
    for (i=0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}


// } Driver Code Ends
class Solution
{
    public:
    void merge(int arr[], int l, int r)
    {
        int m = l + (r - l)/2;
        int l1 = m + 1 - l;
        int l2 = r - m;
        int *first = new int[l1];
        int *second = new int[l2];
        int k = l;
        for(int i = 0; i < l1; i++)first[i] = arr[k++];
        k = m + 1;
        for(int i = 0; i < l2; i++)second[i] = arr[k++];
        k = l;
        int i1 = 0,i2 = 0;
        while(i1 < l1 && i2 < l2){
            if(first[i1] < second[i2]){
                arr[k++] = first[i1++];
            }else{
                arr[k++] = second[i2++];
            }
        }
        while(i1 < l1){
            arr[k++] = first[i1++];
        }
        while(i2 < l2){
            arr[k++] = second[i2++];
        }
        delete [] first;
        delete [] second;
    }
    public:
    void mergeSort(int arr[], int l, int r)
    {
        if(l >= r)return;
        int mid = l+(r-l)/2;
        mergeSort(arr,l,mid);
        mergeSort(arr,mid+1,r);
        merge(arr,l,r);
    }
};

//{ Driver Code Starts.


int main()
{
    int n,T,i;

    scanf("%d",&T);

    while(T--){
    
    scanf("%d",&n);
    int arr[n+1];
    for(i=0;i<n;i++)
      scanf("%d",&arr[i]);

    Solution ob;
    ob.mergeSort(arr, 0, n-1);
    printArray(arr, n);
    }
    return 0;
}
// } Driver Code Ends