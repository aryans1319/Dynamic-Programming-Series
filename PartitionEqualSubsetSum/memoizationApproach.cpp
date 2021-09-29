class Solution {
public:
    int dp[201][20001];
    bool subsetSum(vector<int>nums,int sum,int n){
        
      if(n<=0){
          return false;
      }
        if(sum==0) {
            return true;
        }
        if(dp[n][sum]!=-1){
            return dp[n][sum];
        }
        
        if(nums[n-1]>sum){
            return dp[n][sum]=subsetSum(nums,sum,n-1);
        }
        else{
            return dp[n][sum]=subsetSum(nums,sum,n-1)||subsetSum(nums,sum-nums[n-1],n-1);
        }
    }
       
    bool canPartition(vector<int>& nums) {
        int sum=0;
        int n=nums.size();
        memset(dp,-1,sizeof(dp));
        for(int i=0;i<n;i++){
            sum+=nums[i];}
             if((sum%2) == 0)
         {
             return subsetSum(nums, sum/2,nums.size());
         }
         else{
             return false;
         }
    }
        
    
};
 

