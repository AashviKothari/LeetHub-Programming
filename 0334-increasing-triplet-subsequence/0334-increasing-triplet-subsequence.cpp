class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int left = INT_MAX;
        int mid = INT_MAX;

        for(auto h : nums){
            if(h<=mid) mid = h;
            else if(h<=left) left=h;
            else return true;
        }
        return false;
    }
};