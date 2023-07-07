class Solution {
public:
    int maxConsecutiveAnswers(string s, int k) {
        int n = s.size();
        int start = 0;
        int end = 0;
        int t = 0, f = 0;
        int ans = 0; 

        while (end < n) {
            if (s[end] == 'T') t++;
            else if(s[end] == 'F') f++;

            while (t > k && f > k) {
                if (s[start] == 'T')
                    t--;
                else
                    f--;
                start++;
            }
            ans = max(ans, end - start + 1); 
            end++;
        }

        return ans;
    }
};