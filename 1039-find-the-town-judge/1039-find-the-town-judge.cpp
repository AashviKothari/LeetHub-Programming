class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        if(n==1) return 1;
        if((n!=1) && trust.empty()) return -1;
        map <int,int> mp;
        int k=-1;
        for(int i=0;i<trust.size();i++){
            mp[trust[i][1]]++;
        }
        for(auto it:mp) {
            if(it.second==n-1) k=it.first;
        }
        for(int i=0;i<trust.size();i++){
            if(trust[i][0]==k) return -1;
        }
        return k;
    }
};