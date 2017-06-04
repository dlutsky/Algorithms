#include<vector>
#include<string>

std::vector<std::string> generateParenthesis(int n) {
  std::vector<std::vector<std::string>> dp(n+1);
  dp[0] = {""};
  for(int i=1; i<=n; i++){
    for(int j=0; j<i; j++){
      for(int x=0; x<dp[j].size(); x++){
        for(int y=0; y<dp[i-j-1].size(); y++){
          dp[i].push_back("("+dp[j][x]+")"+dp[i-j-1][y]);
        }
      }
    }
  }
  return dp[n];
}
