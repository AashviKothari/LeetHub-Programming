class Solution {
public:
    int mostFrequentEven(vector<int>& nums) {
        map<int,int>mp;
        int n = nums.size();

        for(auto i : nums){
            if(i%2 == 0){
                mp[i]++;
            }
        }

        int fr = 0;
        int ans = -1;
        for(auto x : mp){
            if(x.second>fr){
                fr = x.second;
                ans = x.first;
            }
        }
        return ans;
    }
};