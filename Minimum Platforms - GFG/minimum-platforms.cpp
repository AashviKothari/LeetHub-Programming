//{ Driver Code Starts
// Program to find minimum number of platforms
// required on a railway station
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    //Function to find the minimum number of platforms required at the
    //railway station such that no train waits.
    int findPlatform(int arr[], int dep[], int n)
    {
    	// Your code here
    	sort(arr,arr+n);
    	sort(dep,dep+n);
    	
    	int plat =1;
    	int res =1;
    	int i = 1; // arival pointer // First train always needs one platform
    	int j = 0; // depature pointer
    	
    	while(i<n && j<n){
    	    if(arr[i]<=dep[j]){ // time of depature is more than time of arrival
    	        plat++;
    	        i++;
    	    }
    	    else if(arr[i]>dep[j]){ //Time of arrival is smaller than depature means a platform gets vacate to plat--
    	        plat--;
    	        j++;
    	    }
    	    
    	    if(plat>res){
    	        res = plat;
    	    }
    	}
    	return res;
    	
    }
};


//{ Driver Code Starts.
// Driver code
int main()
{
    int t;
    cin>>t;
    while(t--) 
    {
        int n;
        cin>>n;
        int arr[n];
        int dep[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        for(int j=0;j<n;j++){
            cin>>dep[j];
        }
        Solution ob;
        cout <<ob.findPlatform(arr, dep, n)<<endl;
    } 
   return 0;
}
// } Driver Code Ends