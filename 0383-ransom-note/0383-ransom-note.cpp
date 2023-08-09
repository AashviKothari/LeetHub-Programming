class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        int n = ransomNote.size();
        int m = magazine.size();

        unordered_map<char,int>mp;

        for(auto it : ransomNote){
            mp[it]++;
        }

        for(auto ij : magazine){
            mp[ij]--;
        }

        for(auto jh : mp){
            if(jh.second > 0){
                return false;
            }
        }
        return true;
    }
};