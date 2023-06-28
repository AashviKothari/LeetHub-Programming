class Solution
{
    public:
        long long minimalKSum(vector<int> &nums, int kk)
        {
            long long k=(kk*1ll);
            sort(nums.begin(),nums.end());
            long long ans = 0;
            int n = nums.size();
            long long  strt = (nums[0]*1ll);
            if (strt > k)
            {
                return (k *(k + 1)) / 2;
            }
            else
            {
                ans += (strt *(strt - 1)) / 2;
                k -= (strt - 1);
                    long long a;
                    long long b;
                for (int i = 0; i < n - 1; i++)
                {
                    a=(nums[i]*1ll);
                    b=(nums[i+1]*1ll);
                    if (b - a > 1)
                    {
                        long long  missing = b -a - 1;
                        if (missing >= k)
                        {
                           	// sum of k terms of an AP : ((a+(a+(k-1)*d))*k)/2
                            ans += ((a + 1 + ((a + 1 + (k - 1)))) *k) / 2;
                            k = 0;
                            return ans;
                        }
                        else
                        {
                            ans += ((a + 1 + (a + 1 + (missing - 1))) *missing) / 2;
                            k -= missing;
                        }
                    }
                }

                if (k > 0)
                {
                   long long c=(nums[n-1]*1ll);
                    ans += ((c + 1 + (c + 1 + (k - 1))) *k) / 2;
                }
            }
            return ans;
        }
};