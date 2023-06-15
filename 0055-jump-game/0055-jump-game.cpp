class Solution {
public:
    bool canJump(vector<int>& nums) {
        int maxJump = 0;
        int n = nums.size();

        for(int i=0;i<n;i++){
            if(maxJump < i) return false;
            maxJump = max(maxJump,i+nums[i]);
        }
        return true;
    }
};