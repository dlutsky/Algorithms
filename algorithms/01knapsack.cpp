#include<vector>
#include<string.h>

#define MAX(x,y) ((x) > (y) ? (x) : (y))

int kanpsack(std::vector<int>& weights, std::vector<int>& values, int W){
	int dp[W+1];
	memset(dp, 0, sizeof(dp));
	for(int i=0; i<weights.size(); i++){
		for(int j=W; j>=weights[i]; j--){
			dp[j] = MAX(dp[j], dp[j-weights[i]]+values[i]);
		}
	}
}
