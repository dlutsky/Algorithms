#include<vector>
#include<unordered_map>

bool checkSubarraySum(std::vector<int>& nums, int k) {
  std::unordered_map<int, int> dp;
  dp[0] = -1;
  int sum = 0;
  for(int i=0; i<nums.size(); i++){
    sum += nums[i];
    if(k!=0){
      sum %= k;
    }
    if(dp.count(sum)){
      if(i-dp[sum] > 1){
        return true;
      }
    }
    else{
      dp[sum] = i;
    }
  }
  return false;
}
