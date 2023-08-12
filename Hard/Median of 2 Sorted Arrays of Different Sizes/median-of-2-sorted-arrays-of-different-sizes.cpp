//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;
double MedianOfArrays(vector<int>& array1, vector<int>& array2);


// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    double MedianOfArrays(vector<int>& array1, vector<int>& array2)
    {
        
        int n1=array1.size();
        int n2=array2.size();
        
        if(n2<n1)  return MedianOfArrays(array2,array1);
        
        int start=0;
        int end=n1;
        while(start<=end){
            int cut1=(start+end)/2;
            int cut2=(n1+n2+1)/2-cut1;
            
            int l1=cut1==0?INT_MIN:array1[cut1-1];
            int l2=cut2==0?INT_MIN:array2[cut2-1];
            int r1=cut1==n1?INT_MAX:array1[cut1];
            int r2=cut2==n2?INT_MAX:array2[cut2];
            
            if(l1<=r2 && l2<=r1){
                if((n1+n2)%2==0){
                    return (max(l1,l2)+min(r1,r2))/2.0;
                }
                else
                    return max(l1,l2)*1.0;
            }
            if(l1>r2){
               end=cut1-1;    
            }
            else{
               start=cut1+1;    
            }
        }
      return 1;    
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int m,n;
        cin>>m;
        vector<int> array1(m);
        for (int i = 0; i < m; ++i){
            cin>>array1[i];
        }
        cin>>n;
        vector<int> array2(n);
        for (int i = 0; i < n; ++i){
            cin>>array2[i];
        }
        Solution ob;
        cout<<ob.MedianOfArrays(array1, array2)<<endl;
    }
    return 0; 
}



// } Driver Code Ends