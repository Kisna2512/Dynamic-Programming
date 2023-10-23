class Solution {
public:

    int solve(int n, vector<int> &nums)
    {
        
	    vector<int> dp1(n,1),cnt(n,1);
        int maxi=0;
	    for (int i = 0; i < n; i++)
        {
         
            for (int prev = 0; prev < i; prev++)
            {
                if (nums[i] > nums[prev]  && 1 + dp1[prev] > dp1[i])
                {
                    dp1[i] = 1 + dp1[prev];
                    cnt[i]=cnt[prev];
                }else if (nums[i] > nums[prev]  && 1 + dp1[prev] == dp1[i])
                {
                    cnt[i]+=cnt[prev];
                }
            }
            maxi=max(maxi,dp1[i]);
           
        }
        int ans=0;
        for(int i=0;i<n;i++)
        {
             if(maxi==dp1[i])
             {
                ans+=cnt[i];
             }
        }

         return ans;
    }



    int findNumberOfLIS(vector<int>& nums) {
        int n=nums.size();
        return solve(n,nums);
    }
};