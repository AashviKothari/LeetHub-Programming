class Solution {
    public: int maxValue(int n, int index, int maxSum) {
        // Setting the initial values is very important, our ans can never be 0 so set low as 1
        int low = 1, mid = 0, high = 1000000000;
        while(low <= high) {
            mid = (low + high) / 2;
            
            // If our ans (which is mid) is making the sum of array more than maxSum means we have to decrease our high
            if(calcAns(mid, index, n) > maxSum) { 
                high = mid - 1;
            } 
            
            // If our ans (which is mid) is so low that even ans + 1 (i.e. mid + 1) is giving better result that means increase our low
            else if(calcAns(mid + 1, index, n)  <= maxSum) {
                low = mid + 1;
            } 
            
            // If our ans (== mid) is such that the sum of array is less than maxSum and even increasing 1 to mid will result the total
            // sum to increase from maxSum, that signifies that we have the answer as mid
            else {
                break;
            }
        }
        
        return mid;
    }
    
    public: int calcAns(int max, int idx, int n) {
        long ret = calcPart(max - 1, idx) + calcPart(max, n - idx);
        if(ret > 1000000000) {
            // Seeing the constraints, if you chose to take high mid value then it might overflow from int. And our answer can never
            // be greater than 10^9 so limit it to that.
            return 1000000001;
        } else {
            
            // This is the sum of the array where max is taken as answer
            return (int)ret;
        }
    }
    public: long calcPart(int a, int num) {
        
        // For AP we need first element (which is "a") and last element (which we calculate in an)
        long an = 0, extraOnes = 0;
        long ans = 0;
        if(num >= a) {
            
            // If total number of elements is more than a which means it will look like
            // a, a - 1, a - 2,  ... , 2, 1 ... followed by extraOnes
            an = 1;
            extraOnes = num - a;
        } else if(num < a) {
            
            // If total number of elements is such that we never reach 1 as our last element means
            // a, a - 1, a - 2 ... a - x, then extraOnes will be 0
            extraOnes = 0;
            an = a - num + 1;
        }
        
        // Sum of AP where we know first and last element = ((first + last) * n) / 2
        ans = ((an + a) * (a - an + 1)) / 2;
        
        // Add extra ones
        ans += extraOnes;
        
        return ans;
    }
};