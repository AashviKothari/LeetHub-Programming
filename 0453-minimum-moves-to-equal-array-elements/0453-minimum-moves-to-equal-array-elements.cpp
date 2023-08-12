class Solution {
public:
    int minMoves(vector<int>& nums) {
        int count = 0;
        sort(nums.begin(), nums.end());
        for(int i=1; i<nums.size(); i++)
            count += nums[i]-nums[0];
        return count;
    }
};