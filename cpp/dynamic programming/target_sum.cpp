class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n=nums.size();
                int count=0;
        int totalSum=0;
        for(int i=0;i<n;i++)
        { if(nums[i]==0)
                    {
                        count++;
                    }
            totalSum+=nums[i];
        }

        int sum= (target+totalSum)/2;
          if((totalSum + (long)target) % 2 == 1 || totalSum <target) return 0;
      int  dp[n+1][sum+1];
        int i=0;
        for( i=0;i<=n;i++)
        {
            for(int j=0;j<=sum;j++)
            {
                if(j==0)
                {
                    dp[i][j]=1;
                }
                else if(i==0)
                {
                    dp[i][j]=0;
                }
                else if(nums[i-1]>j || nums[i-1] == 0)
                {
                   
                    dp[i][j]=dp[i-1][j];
                }
                else
                {
                    dp[i][j]=dp[i-1][j]+ dp[i-1][j-nums[i-1]];
                }
            }
        }
     
        return pow(2,count)*dp[n][sum];
    }
};