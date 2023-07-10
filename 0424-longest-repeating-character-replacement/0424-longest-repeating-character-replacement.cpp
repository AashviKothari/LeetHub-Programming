class Solution {
public:
    int characterReplacement(string s, int k) {
        int i=0, j=0, ans=0, res=0;
        unordered_map<char, int>mp;
        while(i<s.size()){
            mp[s[i]]++;
            ans=max(ans,mp[s[i]]);
            if(i-j+1-ans>k){
                mp[s[j]]--; // j is the left index
                j++;
            }
            res=max(res, i-j+1);
            i++;
        }
       return res; 
    }
};