#include<vector>
#include<set>

bool canCross(std::vector<int>& stones, int index, int gap, std::vector<std::set<int>>& dp, int* pres, int* max){
  if(dp[index].count(gap) || dp[index].count(gap-1) || dp[index].count(gap+1)){
    return true;
  }
  int i=pres[index];
  while(i>=0){
    int g = stones[index] - stones[i];
    if(g==gap || g==gap-1 || g==gap+1 || gap==0){
      if(canCross(stones, i, g, dp, pres, max)){
        dp[index].insert(g);
        if(g > max[index]){
          max[index] = g;
        }
        return true;
      }
    }
    if(g > max[index]){
      return false;
    }
    pres[index] = i-1;
    i--;
  }
  return false;
}
bool canCross(std::vector<int>& stones) {
  int count = stones.size();
  std::vector<std::set<int>> dp(count, std::set<int>());
  dp[0].insert(0);
  int pres[count];
  pres[0] = 0;
  for(int i=1; i<count; i++){
    pres[i] = i-1;
  }
  int max[count];
  max[0] = 0;
  dp[0].insert(0);
  for(int i=1; i<count; i++){
    max[i] = max[i-1];
    canCross(stones, i, 0, dp, pres, max);
  }
  return !dp[count-1].empty();
}
