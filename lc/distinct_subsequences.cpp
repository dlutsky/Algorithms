#include<string>
#include<string.h>

int numDistinct(std::string s, std::string t) {
	int n = t.size();
	int dp[n];
	memset(dp, 0, sizeof(dp));
	int prev;
	for(int i=0; i<s.size(); i++){
		prev = 1;
		for(int j=0; j<n; j++){
			if(s[i] == t[j]){
				std::swap(dp[j], prev);
				dp[j] += prev;
			}else{
				prev = dp[j];
			}
		}
	}
	return dp[n-1];
}
