class Solution {
public:
    int sub (vector<int>&nums, int k){
        int n = nums.size();
        unordered_map<int,int>m;
        int start = 0 , end = 0 , count = 0;

        while(end < n){
            m[nums[end]]++;
            while(m.size()>k){
                m[nums[start]]--;
                if(m[nums[start]] == 0){
                    m.erase(nums[start]);
                }
                start++;
            }
            count += end-start+1;
            end++;
        }
        return count;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return sub(nums,k) - sub(nums, k-1);
    }
};