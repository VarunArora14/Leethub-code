class Solution {
public:
    
    int helper(vector<int>& pref, int L, int M)
    {
        int n=pref.size();
        int maxL=0, ans=0;
        // if L=3 and M=2, 5 elements in [0...4]
        for(int i=L+M;i<n;i++)
        {
            maxL = max(maxL, pref[i-M] - pref[i-M-L]); // L length subarray 
            ans=  max(ans, maxL + pref[i] - pref[i-M]); // maxL + subarray [i-m...i] of length m, why not maxM below
        }
        return ans;
    }
    
    // if you think what if L length subarray in region pref[M...N], then it comes in 2nd case where we call helper(second,first) where maxM lies before maxL so in that case it is not maxL calculated but pref[i]-pref[i-L]
    
    // here L is length of first and M of second. We traverse in such a way that we maximixe maxL and then from that position onwards, we look for pref[i] - pref[i-M] to maximize the M length subarray
        // Keeping maxL helps for finding best L length subarray but not maxM as it will cause overlap
        // consider [1,1,1,3,2,1] where L=2 and M=1 will give maxL=5 (3,2) but maxM as 2 if we just find the max value
        // rather if we keep looking for M length subarray after L length and check max(ans, maxL + pref[i]-pref[i-M])
        // instead of max(maxL+maxM,ans), we will get the correct ans
    
    
    int maxSumTwoNoOverlap(vector<int>& nums, int first, int second) {
        int n=nums.size();
        
        vector<int> pref(n+1);
        pref[0]=nums[0];
        for(int i=1;i<=n;i++)
        {
            pref[i] = pref[i-1] + nums[i-1]; // avoid overflow error
        }
        
        int v1 = helper(pref,first,second); // assuming maxSecond lies after first.length() subarray
        int v2 = helper(pref,second,first); // assuming maxFirst lies after second.length() subarray
        return max(v1,v2);
        
    }
};
// there can be 2 cases, 1. the maxSecond lies before L length subarray
// 2. maxSecond lies after L length subarray
// here we have to maximimize the windows of length  firstLen and secondLen such that they are non overlapping
// for this we can choose index i till which we find the max window of length firstLen and from i+1 to n we maximize window of length secondLen
// we maintain a prefix sum for this so that we can easily find the window in O(1) and compare

// for looping to find the subarray, start with i=first+second, maxFirst = pref[i-second] - pref[i-first]
// and maxSecond = pref[]

// https://leetcode.com/problems/maximum-sum-of-two-non-overlapping-subarrays/discuss/279221/JavaPython-3-two-easy-DP-codes-w-comment-time-O(n)-NO-change-of-input