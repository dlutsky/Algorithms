#include<vector>
#include<unordered_map>

int numberOfArithmeticSlices(std::vector<int>& A) {
  std::vector<std::unordered_map<int, int>> dp;
  int res = 0;
  int d = 0;
  for(int i=0; i<A.size(); i++){
    dp.push_back(std::unordered_map<int, int>());
    for(int j=0; j<i; j++){
      if((long)A[i] - (long)A[j] > INT_MAX || (long)A[i] - (long)A[j] < INT_MIN) continue;
      d = A[i] - A[j];
      dp[i][d] += 1;
      if(dp[j].count(d)){
        dp[i][d] += dp[j][d];
        res += dp[j][d];
      }
    }
  }
  return res;
}
