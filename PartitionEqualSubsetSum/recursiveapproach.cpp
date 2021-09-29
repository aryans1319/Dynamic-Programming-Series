class Solution {
public:
  // Recursive Apprroach
    bool subsetSum(vector<int>nums,int sum,int n){
      if(n<=0){
          return false;
      }
        if(sum==0) {
            return true;
        }
        
        if(nums[n-1]>sum){
            return subsetSum(nums,sum,n-1);
        }
        else{
            return subsetSum(nums,sum,n-1)||subsetSum(nums,sum-nums[n-1],n-1);
        }
    }
  
    bool canPartition(vector<int>& nums) {
        int sum=0;
        int n=nums.size();
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
 

