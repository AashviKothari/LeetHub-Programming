class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
//         vector<int>ans;

//         for(int i =0 ; i<nums.size();i++){
//                 int prod = 1;
//             for(int j=0; j<nums.size();j++){

//                 if(i==j){
//                     continue;
//                 }

//                 prod *= nums[j];
//             }
//             ans.push_back(prod);
//         }
//         return ans;
        int n = nums.size();
        // vector<int>ans(n);
        // vector<int>l(n);
        // vector<int>r(n);

        // l[0]=1;
        // for(int i=1; i < n;i++){
        //     l[i] = l[i-1] * nums[i-1];
        // }

        // r[n-1] = 1;
        // for(int i = n-2; i>=0;i--){
        //     r[i] = r[i+1] * nums[i+1];
        // }

        // for(int i = 0; i<n; i++){
        //     ans[i] = r[i] * l[i];
        // }

        vector<int>ans(n);
        ans[0] = 1;
        for(int i = 1; i<n ;i++){
            ans[i] = ans[i-1] * nums[i-1];
        }

        int right = 1;
        for(int i = n-1; i>=0; i--){
            ans[i]*= right;
            right *= nums[i]; 
        }
        return ans;
    }
};