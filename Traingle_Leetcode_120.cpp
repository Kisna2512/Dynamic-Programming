class Solution {
public:
    
    int ft(int i,int j,vector<vector<int>>& triangle,int n)
    {
        if( i > n || j > triangle[i].size() ){
          return INT_MAX;
        }

          if(i==n-1)
          {
            return triangle[i][j]; 
          }

          int down=triangle[i][j]+ft(i+1,j,triangle,n);
         
          int  right=triangle[i][j]+ft(i+1,j+1,triangle,n);

          return min(down,right);

    }

    int ft(int i,int j,vector<vector<int>>& triangle,int n,vector<vector<int>> &dp)
    {
        if( i > n || j > triangle[i].size() ){
          return INT_MAX;
        }

          if(i==n-1)
          {
            return triangle[i][j]; 
          }

          if(dp[i][j]!=-1)
          {
              return dp[i][j];
          }

          int down=triangle[i][j]+ft(i+1,j,triangle,n,dp);
         
          int  right=triangle[i][j]+ft(i+1,j+1,triangle,n,dp);

          return dp[i][j]=min(down,right);

    }

    int Tab(vector<vector<int>>& triangle,int n)
    {
        int m=triangle[n-1].size();
         vector<vector<int>> dp(n,vector<int>(n,0));
         
         for(int j=0;j<n;j++)
         {
             dp[n-1][j]=triangle[n-1][j];
         }
         for(int i=n-2;i >= 0 ;i--)
         {
             for(int j=i;j >= 0 ;j--)
             {
                int down=triangle[i][j]+dp[i+1][j];
         
          int  right=triangle[i][j]+dp[i+1][j+1];

          dp[i][j]=min(down,right);
                
             }
         }

         return dp[0][0];
    }


    int minimumTotal(vector<vector<int>>& triangle) {
        int n=triangle.size();
        int m=triangle[n-1].size();
        vector<vector<int>> dp(n,vector<int>(m,-1));
        // return ft(0,0,triangle,n,dp);

        return Tab(triangle,n);
    }
};