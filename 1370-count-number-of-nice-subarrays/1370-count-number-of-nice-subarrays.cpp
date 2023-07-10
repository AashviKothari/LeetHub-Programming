class Solution {
public:
    int subArray(vector<int>& nums, int k) {
        int start = 0 , end = 0 , count = 0 , ans = 0;
        int n = nums.size();

        while(end < n){
            if(nums[end]%2 == 1) count++;
            while(count > k){
                if(nums[start] % 2 == 1){
                    count--;
                }
                start++;
            }
            ans += end-start+1;
         end++;
        }
        return ans;
    }
    int numberOfSubarrays(vector<int>& nums, int k) {
      return subArray(nums, k) - subArray(nums, k - 1);
    }
};

