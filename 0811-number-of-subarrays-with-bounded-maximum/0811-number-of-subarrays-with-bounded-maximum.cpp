class Solution {
public:
    int numSubarrayBoundedMax(vector<int>& nums, int left, int right) {
        int n = nums.size();
        int j = 0;
        int ans = 0;

        int preva = 0;

        for(int i = 0; i<n; i++){
            if(nums[i]>=left && nums[i]<=right){
                ans += (i-j+1); 
                preva = (i-j+1);
            }
            else if(nums[i]<left){
                ans+=preva;
            }
            else{
                j = i+1;
                preva = 0;
            }
        }
        return ans;
    }
};