#include<vector>
#include<string.h>

int numberOfArithmeticSlices(std::vector<int>& A) {
  int num = A.size();
  if(num < 3){
    return 0;
  }
  int dp[num];
  memset(dp, 0, sizeof(dp));
  int diff = A[2] - A[1];
  if((A[1]-A[0]) == diff){
    dp[2] = 1;
  }
  int res = dp[2];
  for(int i=3; i<num; i++){
    if((A[i]-A[i-1]) == diff){
      dp[i] = dp[i-1]+1;
    }
    res += dp[i];
    diff = A[i]-A[i-1];
  }
  return res;
}
