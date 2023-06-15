//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    public:
    //Function to find the maximum number of meetings that can
    //be performed in a meeting room.
    
    struct meeting{
            int start;
            int end;
            int pos;
        };
    static bool comp(meeting m1,meeting m2){
        if(m1.end < m2.end) return true;
        else if(m1.end>m2.end) return false;
        else if(m1.pos<m2.pos) return true;
        return false;
    }
    int maxMeetings(int start[], int end[], int n)
    {
        
        meeting m[n];
        for(int i=0;i<n;i++){
            m[i].end = end[i];
            m[i].start = start[i];
            m[i].pos = i+1;
        }
        
        sort(m,m+n,comp);
        int endLimit = m[0].end;
        int ans=1;
        
        for(int i = 1; i<n;i++){
            if(m[i].start>endLimit){
                endLimit=m[i].end;
                ans++;
            }
        }
        return ans;
        // Your code here
        
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int start[n], end[n];
        for (int i = 0; i < n; i++) cin >> start[i];

        for (int i = 0; i < n; i++) cin >> end[i];

        Solution ob;
        int ans = ob.maxMeetings(start, end, n);
        cout << ans << endl;
    }
    return 0;
}
// } Driver Code Ends