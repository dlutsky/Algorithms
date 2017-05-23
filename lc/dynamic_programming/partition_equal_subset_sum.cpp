#include<vector>
#include<string.h>

bool canPartition(std::vector<int>& nums) {
  int sum = 0;
  for(int i=0; i<nums.size(); i++){
    sum += nums[i];
  }
  if(sum%2 == 1){
    return false;
  }
  sum = sum/2;
  bool dp[sum+1];
  memset(dp, 0, sizeof(dp));
  for(int i=0; i<nums.size(); i++){
    if(nums[i] > sum){
      return false;
    }
    for(int j=sum; j>=nums[i]; j--){
      if(dp[j-nums[i]]){
        dp[j] = true;
      }
    }
    dp[nums[i]] = true;
  }
  return dp[sum];
}
