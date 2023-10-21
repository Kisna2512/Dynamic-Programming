class Solution {
public:
      
    bool checkS(string &s1,string &s2)
    {
        if(s1.size() != s2.size()+1)
        {
           return false;
        }
        int i=0,j=0;
        while(i < s1.size())
        {
            if(s1[i]==s2[j])
            {
                i++;
                j++;
            }else
            {
                i++;
            }
        }

        if(i==s1.size() && j==s2.size())
        {
            return true;
        }
        return false;
    }

     bool static comp(string &s1,string &s2)
     {
         return s1.size() < s2.size();
     }

    int solveS(int n, vector<string> &nums)
    {
        vector<int> dp(n, 1);
       
        int maxi = 1;
       
        sort(nums.begin(),nums.end(),comp);
        for (int i = 0; i < n; i++)
        {
           
            for (int prev = 0; prev < i; prev++)
            {
                if (checkS(nums[i],nums[prev])==true && 1 + dp[prev] > dp[i])
                {
                    dp[i] = 1 + dp[prev];
                  
                }
            }
            if (dp[i] > maxi)
            {
                maxi = dp[i];
            }
        }
       return maxi;
        
    }


    int longestStrChain(vector<string>& words) {
        int n=words.size();
        return solveS(n,words);
    }
};