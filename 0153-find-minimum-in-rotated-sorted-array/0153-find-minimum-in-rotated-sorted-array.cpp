class Solution {
public:
    int findMin(vector<int>& nums) {
        int n=nums.size();
        int low=0,high=n-1;
        int mini=INT_MAX;
        while(low<=high)
        {
            int mid=(low)+(high-low)/2;
            if(nums[low]<=nums[mid])//Left is sorted
            {
                mini=min(mini,nums[low]);
                low=mid+1;
            }else{//right is sorted
                if(nums[mid]<=nums[high])
                {
                    mini=min(mini,nums[mid]);
                    high=mid-1;
                }
            }
        }
        return mini;
    }
};